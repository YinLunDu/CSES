#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

set <int> G[200005];
vector <int> order;
int in[200005], out[200005];

void dfs(int v)
{
    while (!G[v].empty()) {
        int u = *G[v].begin();
        G[v].erase(u);
        dfs(u);
    }
    order.push_back(v);
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
        G[a].insert(b);
        out[a]++;
        in[b]++;
    }
    
    in[1]++;
    out[n]++;
    bool flag = true;
    for (i=1; i<=n; i++) {
        if (in[i] != out[i])
            flag = false;
    }

    if (!flag) {
        cout << "IMPOSSIBLE\n";
    } else {
        dfs(1);
        if ((int)order.size() != m + 1) {
            cout << "IMPOSSIBLE\n";
        } else {
            reverse(order.begin(), order.end());
            for (int v:order)
                cout << v << " ";
            cout << "\n";
        }
    }
    
    return 0;
}