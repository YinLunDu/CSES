#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

const int INF = 1e18;
int n, x, arr[22];
int dp[1 << 22], last[1 << 22];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i;
    cin >> n >> x;
    for (i=0; i<n; i++)
        cin >> arr[i];
    
    fill(dp, dp + (1 << 22), INF);
    fill(last, last + (1 << 22), INF);

    dp[0] = 1;
    last[0] = 0;

    for (int s=1; s<(1 << n); s++) {
        for (int i=0; i<n; i++) {
            if (s & (1 << i)) {
                int pre = s ^ (1 << i);
                if (last[pre] + arr[i] > x) {
                    if (dp[pre] + 1 < dp[s] ||
                        (dp[pre] + 1 == dp[s] && arr[i] < last[s])) {

                        dp[s] = dp[pre] + 1;
                        last[s] = arr[i];
                    }
                } else {
                    if (dp[pre] < dp[s] ||
                        (dp[pre] == dp[s] && last[pre] + arr[i] < last[s])) {

                        dp[s] = dp[pre];
                        last[s] = last[pre] + arr[i];
                    }
                }
            }
        }
    }

    cout << dp[(1 << n) - 1] << "\n";
/*
    for (i=0; i<=(1 << n)-1; i++)
        cout << ((dp[i] != INF) ? dp[i] : -1) << " ";
    cout << "\n";
    for (i=0; i<=(1 << n)-1; i++)
        cout << ((last[i] != INF) ? last[i] : -1) << " ";
*/
    return 0;
}