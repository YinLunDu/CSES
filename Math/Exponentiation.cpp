#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

const int mod = 1e9 + 7;

struct comb
{
    int n;

    comb() : n{0} {}

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
};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    comb c;
    int q, a, b;
    cin >> q;
    while (q--) {
        cin >> a >> b;
        cout << c.fastpow(a, b) << "\n";
    }

    return 0;
}