#include <bits/stdc++.h>
#define int long long

using namespace std;

bool dp[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,i,j,tmp;
    fill(dp, dp+100005, false);
    cin >> n;

    dp[0]=true; int cnt=0;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        for (j=100000;j>=1;j--) {
            if (j-tmp<0) continue;
            if (dp[j]==true) continue;

            if (dp[j-tmp]==true) {
                dp[j] |= dp[j-tmp];
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
    for (i=1;i<=100000;i++)
        if (dp[i])
            cout << i << " ";
    return 0;
}

