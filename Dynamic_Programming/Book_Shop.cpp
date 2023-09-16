#include <bits/stdc++.h>
#define int long long

using namespace std;

int dp[100005];

signed main()
{
    int n, x;
    int i, j;
    ///  price    page
    int h[1005], s[1005];
    cin >> n >> x;
    for (i = 1; i <= n; i++) cin >> h[i];
    for (i = 1; i <= n; i++) cin >> s[i];

    fill(dp, dp + 100005, -1);
    dp[0] = 0;
    for (i = 1; i <= n; i++) {
        for (j = x; j >= 1; j--) {
            if (j - h[i] >= 0)
                dp[j] = max(dp[j], dp[j-h[i]] + s[i]);
        }
    }
    
    int ans = 0;
    for (i = 1; i <= x; i++)
        ans = max(ans, dp[i]);
    cout << ans << "\n";
    return 0;
}
