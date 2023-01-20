#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

const int mod = 1e9+7;
int fac[505];
int inv[505];
int dp[505][505];

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
    for (i=2;i<=500;i++)
        fac[i] = (fac[i-1] * i) % mod;
}

void init_inv()// Inverse 模反元素
{
    int i;
    inv[0] = 1;
    inv[1] = 1;
    for (i=2;i<=500;i++)
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

    string s;
    cin >> s;
/// @brief  dp[i][j] = dp[i+1][k-1] * dp[k+1][j] * C( (j-i+1)/2, (k-i+1)/2 ) , where s[i] = s[k]
    int i, j, k, sz = s.size();
    
    int tmp;
    for (i = sz-1; i >= 0; i--) {
        for (j = i; j <= sz-1; j++) {     

            if (i == j) continue;
            if (j-i == 1) {dp[i][j] = (s[i]==s[j]); continue;}

            for (k = i+1; k <= j; k++) {
                if (s[i] == s[k]) {
                    if (k+1 > j)
                        tmp = (dp[i+1][k-1] * C((j-i+1)/2, (k-i+1)/2)) % mod;
                    else if (i+1 > k-1)
                        tmp = (dp[k+1][j]* C((j-i+1)/2, (k-i+1)/2)) % mod;
                    else
                        tmp = (((dp[i+1][k-1] * dp[k+1][j]) % mod) * C((j-i+1)/2, (k-i+1)/2)) % mod;
                    dp[i][j] = (dp[i][j] + tmp) % mod;
                }
            }
            
        }
    }

    cout << dp[0][sz-1] << "\n";
    
    return 0;
}