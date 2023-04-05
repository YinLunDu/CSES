#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector<int> G[200005];
int dp[20][200005];
int depth[200005];

void dfs(int v, int p)
{
    dp[0][v] = p;
    for (int u:G[v]) {
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    int step = depth[a] - depth[b];
    for (int i=0; i<=18; i++) {
        if (step & (1 << i))
            a = dp[i][a];
    }

    if (a == b) return a;
    for (int i=18; i>=0; i--) {
        if (dp[i][a] != dp[i][b]) {
            a = dp[i][a];
            b = dp[i][b];
        }
    }
    return dp[0][a];
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    int i, j, a, b;
    for (i=1; i<=n-1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    depth[1] = 0;
    dfs(1, 0);
    
    for (i=1; i<=18; i++) {
        for (j=1; j<=n; j++) {
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }

    while (q--) {
        cin >> a >> b;
        int c = lca(a, b);
        int res = depth[a] - depth[c] + depth[b] - depth[c];
        cout << res << "\n";
    }
    
    return 0;
}