#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[5005][5005];

signed main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int i, j;
    int n = s1.size();
    int m = s2.size();

    for (i = 1; i <= n; i++)
        dp[i][0] = i;
    for (j = 1; j <= m; j++)
        dp[0][j] = j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(min(dp[i-1][j] + 1,dp[i][j-1] + 1),dp[i-1][j-1] + 1);
        }
    }

    cout << dp[n][m] << "\n";
    return 0;
}
