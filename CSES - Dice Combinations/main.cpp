#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

ll dp[1000002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    ll i;
    cin >> n;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    dp[4]=8;
    dp[5]=16;
    dp[6]=32;
    for (i=7;i<=n;i++)
        dp[i] = (dp[i-6]+dp[i-5]+dp[i-4]+dp[i-3]+dp[i-2]+dp[i-1]) % MOD;
    cout << dp[n] << "\n";
    return 0;
}
