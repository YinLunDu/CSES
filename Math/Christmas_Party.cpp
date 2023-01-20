#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

const int mod = 1e9+7;
int fac[1000005];
int inv[1000005];

int fastpow(int a, int b)
{
    int res = a, ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * res) % mod;
        res = (res * res) % mod;
        b /= 2;
    }
    return ans;
}

int mul(int x) // Multiplicative Inverse 模反元素
{
    return fastpow(x, mod-2);
}

void init_fac()// Factorial 階層
{
    int i;
    fac[0] = 1;
    fac[1] = 1;
    for (i=2;i<=1000000;i++)
        fac[i] = (fac[i-1] * i) % mod;
}

void init_inv()// Inverse 模反元素
{
    int i;
    inv[0] = 1;
    inv[1] = 1;
    for (i=2;i<=1000000;i++)
        inv[i] = (inv[i-1] * mul(i)) % mod;
}

int C(int m, int n)
{
    return ((((fac[m] * inv[n]) % mod ) * inv[m-n]) % mod);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    init_fac();
    init_inv();
    
    int n;
    cin >> n;
    int sum = 0, i;
    
    for (i=0;i<=n;i++) {
        if (i % 2 == 0)
            sum = (sum + (C(n, i) * fac[n-i]) % mod) % mod;
        else
            sum = (sum - (C(n, i) * fac[n-i]) % mod) % mod;
    }
    cout << (sum + mod) % mod << "\n";

    return 0;
}