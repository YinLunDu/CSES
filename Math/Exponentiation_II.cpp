#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

const int mod = 1e9 + 7;

struct comb {
    int n;

    comb() : n{0} {}

    int fastpow(int a, int b, int M) {
        int res = a, ans = 1;
        while (b > 0) {
            if (b & 1) ans = (ans * res) % M;
            res = (res * res) % M;
            b /= 2;
        }
        return ans;
    }
};

/// a ^ -1 = a ^ (M - 2) (mod M)
///      1 = a ^ (M - 1) (mod M)

signed main()
{
    comb C;
    int q, a, b, c;
    cin >> q;
    while (q--) {
        cin >> a >> b >> c;
        int d = C.fastpow(b, c, mod - 1);
        cout << C.fastpow(a, d, mod) << "\n";
    }

    return 0;
}