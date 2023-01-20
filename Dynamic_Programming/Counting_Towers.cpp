/**
 https://www.youtube.com/watch?v=MxhA0bY31wM
 **/
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD=1e9+7;
int dp[1000005][10];

signed main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int i,j;

    for (j=1;j<=8;j++)
        dp[1][j]=1;

    for (i=2;i<=1000005;i++) {
        for (j=1;j<=8;j++) {
            if (j==1 || j==3 || j==4 || j==5 || j==6)
                dp[i][j]=(dp[i-1][1]+
                          dp[i-1][2]+
                          dp[i-1][4]+
                          dp[i-1][5]+
                          dp[i-1][6])%MOD;
            else
                dp[i][j]=(dp[i-1][3]+
                          dp[i-1][7]+
                          dp[i-1][8])%MOD;
        }
    }


    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << (dp[x][3]+dp[x][7])%MOD << "\n";
    }
    return 0;
}
