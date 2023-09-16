#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector <pii> G[100005];
bool vis[100005], flag = false;
int depth[100005], low[100005];
bool output[200005];
vector <pii> ans;

void dfs(int v, int p)
{
    vis[v] = true;
    depth[v] = low[v] = (p == -1 ? 1 : depth[p] + 1);
    for (pii u:G[v]) {
        if (u.first == p) continue;

        if (!output[u.second]) {
            ans.push_back({v, u.first});
            output[u.second] = true;
        }

        if (!vis[u.first]) {
            dfs(u.first, v);
            if (low[u.first] >= depth[v] && p != -1)
                flag = true;
            low[v] = min(low[v], low[u.first]);
        } else {
            low[v] = min(low[v], depth[u.first]);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, a, b;
    cin >> n >> m;
    
    for (i=1; i<=m; i++) {
        cin >> a >> b;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }

    dfs(1, -1);

    if (flag || (int)ans.size() != m) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (pii tmp:ans)
            cout << tmp.first << " " << tmp.second << "\n";
    }
    
    return 0;
}