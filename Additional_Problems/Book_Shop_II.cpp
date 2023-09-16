#include <bits/stdc++.h>
#define int long long
using namespace std;

vector <pair<int, int>> item;
int dp[100005];

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin >> n >> x;

/// price page copy
    int h[105], s[105], k[105];

    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> k[i];

    for (int i = 1; i <= n; i++) {
        int tmp = 1;
        int hh = h[i], ss = s[i], kk = k[i];
        while (kk > tmp) {
            item.push_back({tmp * hh, tmp * ss});
            kk -= tmp;
            tmp *= 2;
        }
        if (kk != 0) item.push_back({kk * hh, kk * ss});
    }

    fill(dp, dp + 100005, -1);
    dp[0] = 0;
    for (auto it : item) {
        for (int j = x; j >= 1; j--) {
            if (j - it.first >= 0) {
                dp[j] = max(dp[j], dp[j - it.first] + it.second);
            }
        }
    }

    int mx = 0;
    for (int i = 1; i <= x; i++)
        mx = max(mx, dp[i]);
    cout << mx << "\n";

    return 0;
}