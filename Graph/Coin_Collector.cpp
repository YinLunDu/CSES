#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector <int> G[200005], rev_G[200005], order, topo_G[200005], topo;
bool vis[200005];
int arr[200005], scc[200005], in[200005], w[200005], dp[200005];

void rev_dfs(int v)
{
    vis[v] = true;
    for (int u:rev_G[v]) {
        if (!vis[u])
            rev_dfs(u);
    }
    order.push_back(v);
}

void dfs(int v, int x)
{
    scc[v] = x;
    for (int u:G[v]) {
        if (scc[u] == -1)
            dfs(u, x);
    }
}

int kosaraju(int n)
{
    order.clear();
    for (int i=1; i<=n; i++) {
        if (!vis[i])
            rev_dfs(i);
    }
    int scc_cnt = 0;
    fill(scc, scc + 200005, -1);
    for (int i=n-1; i>=0; i--) {
        int v = order[i];
        if (scc[v] == -1)
            dfs(v, ++scc_cnt);
    }
    return scc_cnt;
}

void topological_sort(int n)
{
    queue <int> q;
    for (int i=1; i<=n; i++) {
        if (!in[i])
            q.push(i);
    }
    while (!q.empty()) {
        int v = q.front();
        topo.push_back(v);
        q.pop();
        for (int u:topo_G[v]) {
            in[u]--;
            if (!in[u]) {
                q.push(u);
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i;
    cin >> n >> m;
    for (i=1; i<=n; i++)
        cin >> arr[i];
    
    int a, b;
    for (i=1; i<=m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        rev_G[b].push_back(a);
    }

    int scc_cnt = kosaraju(n);

    for (i=1; i<=n; i++)
        w[scc[i]] += arr[i];
    
    for (int v=1; v<=n; v++) {
        for (int u:G[v]) {
            if (scc[v] == scc[u]) continue;
            topo_G[scc[v]].push_back(scc[u]);
            in[scc[u]]++;
        }
    }

    topological_sort(scc_cnt);

    for (i=1; i<=scc_cnt; i++)
        dp[i] = w[i];

    int ans = -1;
    for (int v:topo) {
        for (int u:topo_G[v]) {
            dp[u] = max(dp[u], w[u] + dp[v]);
            ans = max(ans, dp[u]);
        }
    }
    cout << ans << "\n";

    return 0;
}