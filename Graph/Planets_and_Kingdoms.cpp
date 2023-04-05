#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector <int> G[200005], rev_G[200005], order;
bool vis[200005];
int scc[200005];

void rev_dfs(int v)
{
    vis[v] = true;
    for (int u:rev_G[v]) {
        if (!vis[u])
            rev_dfs(u);
    }
    order.push_back(v);
}

void dfs(int v, int block)
{
    scc[v] = block;
    for (int u:G[v]) {
        if (scc[u] == -1)
            dfs(u, block);
    }
}

int kosaraju(int n)
{
    for (int i=1; i<=n; i++) {
        if (!vis[i])
            rev_dfs(i);
    }

    int scc_cnt = 0;
    fill(scc, scc + 200005, -1);

    for (int i=n-1; i>=0; i--) {
        int v = order[i];
        if (scc[v] == -1) {
            dfs(v, ++scc_cnt);
        }
    }
    return scc_cnt;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i=1; i<=m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        rev_G[b].push_back(a);
    }

    int ans = kosaraju(n);

    cout << ans << "\n";
    for (int i=1; i<=n; i++)
        cout << scc[i] << " ";
    cout << "\n";
    
    return 0;
}