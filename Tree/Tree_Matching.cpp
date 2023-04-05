/*
dp(i, 0) 不選 i ， i 子樹的最大 matching
dp(i, 1)   選 i ， i 子樹的最大 matching

dp(v, 0) = SUM( max(dp(u, 0), dp(u, 1)) )
dp(v, 1) = { dp(v, 0) - max(dp(x, 0), dp(x, 1)) } + { dp(x, 0) + 1 }
*/
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int dp[200005][2];
vector<int> G[200005];

void dfs(int v, int p)
{
    int cnt = 0;
    for (int u:G[v]){
        if (u == p) continue;
        dfs(u, v);
        cnt += max(dp[u][0], dp[u][1]);
    }
    dp[v][0] = cnt;
    int mx = -1e18;
    for (int u:G[v]){
        if (u == p) continue;
        int tmp = dp[u][0] + 1 - max(dp[u][0], dp[u][1]);
        mx = max(mx, tmp);
    }
    dp[v][1] = cnt + mx;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int i, a, b;
    for (i=1; i<=n-1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]) << "\n";
    return 0;
}