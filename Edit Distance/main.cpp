#include <bits/stdc++.h>
#define int long long

using namespace std;

int dp[5005][5005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int i,j;
    int sz1=s1.size();
    int sz2=s2.size();

    for (i=0;i<=sz1;i++)
        dp[i][0]=i;
    for (j=0;j<=sz2;j++)
        dp[0][j]=j;

    for (i=1;i<=sz1;i++) {
        for (j=1;j<=sz2;j++) {
            if (s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+1);
        }
    }
    cout << dp[sz1][sz2] << "\n";
    return 0;
}
