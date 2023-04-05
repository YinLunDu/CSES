#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector<int> G[200005];
int dpf[200005];
int dps[200005];
int ans[200005];
int c[200005];

void dfs(int v, int p)
{
    for (int u:G[v]) {
        if (u == p) continue;
        dfs(u, v);
        int cnt = dpf[u] + 1;
        if (cnt > dpf[v]) {
            dps[v] = dpf[v];
            dpf[v] = cnt;
            c[v] = u;
        } else if (cnt > dps[v]) {
            dps[v] = cnt;
        }
    }
    return;
}

void dfs2(int v, int p)
{
    int cnt = 0;
    for (int u:G[v]) {
        if (u == p) continue;

        if (c[v] == u) {
            if (dpf[u] < dps[v] + 1) {
                dps[u] = dpf[u];
                dpf[u] = dps[v] + 1;
                c[u] = v;
            } else if (dps[u] < dps[v] + 1) {
                dps[u] = dps[v] + 1;
            }
        } else {
            dps[u] = dpf[u];
            dpf[u] = dpf[v] + 1;
            c[u] = v;
        }
        dfs2(u, v);
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
        cout << dpf[i] << " ";
    cout << "\n";

    return 0;
}