#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

const int mod = 1e9+7;

struct comb {
    int n;
    vector <int> _fac;
    vector <int> _inv;
    vector <int> _invfac;

    comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}

    int fastpow(int a, int b) {
        int res = a, ans = 1;
        while (b > 0) {
            if (b & 1) ans = (ans * res) % mod;
            res = (res * res) % mod;
            b /= 2;
        }
        return ans;
    }
    int inv(int x) { return fastpow(x, mod-2); }
    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);
        
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = (_fac[i - 1] * i) % mod;
        }
        _invfac[m] = inv(_fac[m]);
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = (_invfac[i] * i) % mod;
            _inv[i] = (_invfac[i] * _fac[i - 1]) % mod;
        }
        n = m;
    }
    int calc_inv(int x) { /// x ^ -1
        if (x > n) init(x);
        return _inv[x];
    }
    int calc_fac(int x) { /// x !
        if (x > n) init(x);
        return _fac[x];
    }
    int C(int x, int y) { /// C(m, n)
        if (x > n) init(x);
        return ((((_fac[x] * _invfac[y]) % mod ) * _invfac[x - y]) % mod);
    }
};

signed main() {
    comb Q;
    
    int n, m;
    cin >> n >> m;

    cout << Q.C(n + m - 1, m) << "\n";
    
    return 0;
}