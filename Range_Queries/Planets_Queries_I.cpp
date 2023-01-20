/**
 * @brief log2_(10^9) = 29.9
 * 
 */
#include <bits/stdc++.h>
#define int long long

using namespace std;

int arr[200005];
int dp[200005][35];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    int i,j;
    for (i=1;i<=n;i++)
        cin >> arr[i];
    
    for (i=1;i<=n;i++)
        dp[i][0]=arr[i];
    for (i=1;i<=31;i++) {
        for (j=1;j<=n;j++) {
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }

    int x,k;
    while (q--) {
        cin >> x >> k;
        int point=x;
        for (i=0;i<=31;i++) {
            if ( k & (1 << i) )
                point=dp[point][i];
        }
        cout << point << "\n";
    }

    return 0;
}