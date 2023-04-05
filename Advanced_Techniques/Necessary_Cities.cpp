#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector <int> G[200005];
int low[200005], dep[200005];
bool vis[200005], cut[200005];

void dfs(int v, int p)
{
    vis[v] = 1;
    int child = 0;
    low[v] = dep[v] = (p == -1 ? 1 : dep[p] + 1);
    for (int u:G[v]) {
        if (u == p) continue;
        if (!vis[u]) {
            dfs(u, v);
            child++;
            low[v] = min(low[v], low[u]);
            if (low[u] >= dep[v] && p != -1)
                cut[v] = true;
        } else {
            low[v] = min(low[v], dep[u]);
        }
    }
    if (p == -1 && child >= 2)
        cut[v] = true;
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

    int cnt = 0;
    for (i=1; i<=n; i++)
        if (cut[i])
            cnt++;
    cout << cnt << "\n";
    for (i=1; i<=n; i++)
        if (cut[i])
            cout << i << " ";
    cout << "\n";
    
    return 0;
}