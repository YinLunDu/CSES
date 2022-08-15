/// Sparse Table
#include <bits/stdc++.h>
#define int long long

using namespace std;

int dp[200005][30];
int arr[200005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    int i,j;
    cin >> n >> q;

    fill(&dp[0][0], &dp[0][0]+200005*30, 1e9);

    for (i=1;i<=n;i++) {
        cin >> arr[i];
        dp[i][0]=arr[i];
    }

/// dp[i][j]=min( dp[ i ][ j-1 ], dp[ i+2^(j-1) ][ j-1 ] )

    for (j=1;j<=25;j++) {
        for (i=1; i+ (1<<j-1) <= n;i++) {
            dp[i][j]=min(dp[i][j-1], dp[ i+ (1<<j-1) ][j-1]);
        }
    }

    int L, R;
    while (q--) {
        cin >> L >> R;
        int T=__lg(R-L+1);
        cout << min(dp[L][T], dp[R - (1 << T) + 1][T]) << "\n";
    }

    return 0;
}
