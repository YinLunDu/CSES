#include <bits/stdc++.h>
#define ll long long

const int MOD=1e9+7;

using namespace std;

ll dp[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x;
    cin >> n >> x;
    ll i,j,v[102];

    dp[0]=1;
    for (i=1;i<=n;i++)
        cin >> v[i];
    for (i=1;i<=x;i++) {
        for (j=1;j<=n;j++) {
            if (i-v[j]>=0)
                dp[i]=(dp[i]+dp[i-v[j]]) % MOD;
        }
    }
    cout << dp[x] << "\n";
    return 0;
}
