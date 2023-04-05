#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector<int> G[200005];
int sz[200005];
int sum[200005];
int ans[200005];
void dfs(int v, int p)
{
    sz[v] = 1, sum[v] = 0;
    for (int u:G[v]) {
        if (u == p) continue;
        dfs(u, v);
        sz[v] += sz[u];
        sum[v] += sum[u] + sz[u];
    }
    return;
}

void dfs2(int v, int p)
{
    ans[v] = sum[v];
    for (int u:G[v]) {
        if (u == p) continue;
        sz[v] -= sz[u];
        sum[v] -= (sum[u] + sz[u]);
        sz[u] += sz[v];
        sum[u] += (sum[v] + sz[v]);

        dfs2(u, v);

        sz[u] -= sz[v];
        sum[u] -= (sum[v] + sz[v]);
        sz[v] += sz[u];
        sum[v] += (sum[u] + sz[u]);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i, a, b;
    cin >> n;
    for (i=1; i<=n-1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, -1);
    dfs2(1, -1);

    for (i=1; i<=n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    
    return 0;
}