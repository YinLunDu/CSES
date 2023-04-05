#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

set <int> G[200005];
vector <int> order;
int n, deg[200005];

void dfs(int v)
{
    while (!G[v].empty()) {
        int u = *G[v].begin();
        G[v].erase(u);
        G[u].erase(v);
        dfs(u);
    }
    order.push_back(v);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> n >> m;
    int a, b;
    for (int i=1; i<=m; i++) {
        cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
        deg[a]++;
        deg[b]++;
    }

    int odd_cnt = 0;
    for (int i=1; i<=n; i++)
        if (deg[i] % 2 == 1)
            odd_cnt++;

    if (odd_cnt) {
        cout << "IMPOSSIBLE\n";
    } else {
        dfs(1);
        if ((int)order.size() != m + 1) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (int it:order)
                cout << it << " ";
            cout << "\n";
        }
    }
    
    return 0;
}