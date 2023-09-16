// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define STL(x) for(auto &HEHE:x) cout << HEHE << " "; cout << "\n";
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void enter() {cout << "\n";}
/// ------- Initialization End -------

const int mod = 1e9 + 7;
int invfac[1000005], fac[1000005];

int fastpow(int a, int k)
{
    int ans = 1, res = a;
    while (k > 0) {
        if (k & 1) ans = (ans * res) % mod;
        res = (res * res) % mod;
        k >>= 1;
    }
    return ans;
}

signed main()
{
    IOS
    
    int MX = 1000000;
    fac[0] = 1;
    for (int i = 1; i <= MX; i++)
        fac[i] = (fac[i - 1] * i) % mod;

    invfac[MX] = fastpow(fac[MX], mod - 2);
    for (int i = MX; i >= 1; i--)
        invfac[i - 1] = (invfac[i] * i) % mod;

    int q, a, b;

    cin >> q;
    while (q--) {
        cin >> a >> b;
        if (a < b)
            cout << 0 << "\n";
        else
            cout << ((fac[a] * invfac[b]) % mod * invfac[a - b]) % mod << "\n";
    }

    return 0;
}