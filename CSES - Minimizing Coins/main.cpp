#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x,v;
    cin >> n >> x;

    fill(dp, dp+1000002, 1e18);
    dp[0]=0;
    ll i,j;
    for (i=1;i<=n;i++) {
        cin >> v;
        for (j=1;j<=x;j++) {
            if (j-v<0) continue;

            dp[j]=min(dp[j], dp[j-v]+1);
        }
    }
    (dp[x]==1e18) ? cout << "-1\n" : cout << dp[x] << "\n";
    return 0;
}
