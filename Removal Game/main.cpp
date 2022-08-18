#include <bits/stdc++.h>
#define int long long

using namespace std;

int arr[5005], pre[5005];
int dp[5005][5005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int i,j;
    pre[0]=0;
    for (i=1;i<=n;i++) {
        cin >> arr[i];
        pre[i]=pre[i-1]+arr[i];
    }

    for (i=1;i<=n;i++)
        dp[i][i]=arr[i];

    for (i=n;i>=1;i--)
        for (j=i+1;j<=n;j++)
            dp[i][j]=max((pre[j]-pre[i-1])-dp[i+1][j],
                         (pre[j]-pre[i-1])-dp[i][j-1]);
    cout << dp[1][n] << "\n";
    return 0;
}
