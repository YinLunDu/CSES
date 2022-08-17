#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD=1e9+7;
int arr[100005];
int dp[100005][105];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int i, j;
    for (i=1;i<=n;i++)
        cin >> arr[i];

    if (arr[1]==0) {
        for (i=1;i<=m;i++)
            dp[1][i]=1;
    } else
        dp[1][arr[1]]=1;

    for (i=2;i<=n;i++) {
        for (j=1;j<=m;j++) {
            if (arr[i]==0)
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%MOD;
            else if (arr[i]==j)
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%MOD;
        }
    }
/*
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
*/
    int sum=0;
    for (i=1;i<=m;i++)
        sum=(sum+dp[n][i])%MOD;
    cout << sum << "\n";
    return 0;
}
