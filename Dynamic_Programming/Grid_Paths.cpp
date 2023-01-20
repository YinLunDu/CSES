#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[1005][1005];
const int MOD=1e9+7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,i,j;
    cin >> n;
    char c;

    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) {
            cin >> c;
            if (c=='*')
                dp[i][j]=0;
            else {
                if (i==1 && j==1)
                    dp[i][j]=1;
                else if (i==1)
                    dp[i][j]=dp[i][j-1]%MOD;
                else if (j==1)
                    dp[i][j]=dp[i-1][j]%MOD;
                else
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
            }
        }
    }
    cout << dp[n][n] << "\n";
    return 0;
}
