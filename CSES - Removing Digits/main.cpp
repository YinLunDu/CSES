#include <bits/stdc++.h>

using namespace std;

int dp[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; int i,j;
    cin >> n;

    dp[0]=0;
    for (i=1;i<=9;i++)
        dp[i]=1;
    for (i=10;i<=n;i++) {
        string s=to_string(i);
        int small=10000000;
        for (j=0;j<(int)s.size();j++) {
            int tmp=s[j]-'0';
            if (tmp!=0)
                small=min(small, dp[i-tmp]);
        }
        dp[i]=small+1;
    }

    cout << dp[n] << "\n";
    return 0;
}
