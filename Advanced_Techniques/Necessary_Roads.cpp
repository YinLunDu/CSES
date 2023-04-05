#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector <int> G[200005];
int low[200005], depth[200005];
bool vis[200005];
vector <pii> bridge;

void dfs(int v, int p)
{
    vis[v] = 1;
    low[v] = depth[v] = (p == -1 ? 1 : depth[p] + 1);
    for (int u:G[v]) {
        if (u == p) continue;
        if (!vis[u]) {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
        } else {
            low[v] = min(low[v], depth[u]);
        }
    }
    if (low[v] == depth[v] && p != -1)
        bridge.push_back({p, v});
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i;
    cin >> n >> m;
    int a, b;
    for (i=1; i<=m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, -1);

    cout << bridge.size() << "\n";

    for (pii it:bridge)
        cout << it.first << " " << it.second << "\n";
    
    return 0;
}