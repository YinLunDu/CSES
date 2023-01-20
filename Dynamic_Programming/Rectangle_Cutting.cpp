#include <bits/stdc++.h>
#define int long long

using namespace std;

int dp[505][505];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin >> a >> b;
    int i,j,k;

    fill(&dp[0][0], &dp[0][0]+505*505, 1e18);

    for (i=1;i<=min(a,b);i++)
        dp[i][i]=0;

    for (i=1;i<=a;i++) {
        for (j=1;j<=b;j++) {
            if (i==j) continue;

            for (k=1;k<=i-1;k++) { /// cut place
                dp[i][j]=min(dp[i][j],
                             dp[k][j]+dp[i-k][j]+1);
            }
            for (k=1;k<=j-1;k++) { /// cut place
                dp[i][j]=min(dp[i][j],
                             dp[i][k]+dp[i][j-k]+1);
            }
        }
    }
    cout << dp[a][b] << "\n";
    return 0;
}
