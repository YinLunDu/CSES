#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

vector<int> G[200005];
int vis[200005];
stack<int> s;
vector<int> ans;

bool dfs(int v)
{
    if (vis[v]) return 0;
    s.push(v);
    vis[v] = 1;
    for (auto u:G[v]) {
        if (vis[u] == 1) {
            ans.push_back(u);
            while (!s.empty() && s.top() != u) {
                ans.push_back(s.top());
                s.pop();
            }
            ans.push_back(u);
            return 1;
        }
        if (dfs(u)) return 1;
    }
    s.pop();
    vis[v] = 2;
    return 0;
}

signed main()
{
    fastio
    int n, k, a, b;
    cin >> n >> k;
    for (int i=1; i<=k; i++) {
        cin >> a >> b;
        G[a].push_back(b);
    }
    
    for (int i=1; i<=n; i++) {
        if (dfs(i)) {
            cout << ans.size() << "\n";
            reverse(ans.begin(), ans.end());
            for (int j:ans)
                cout << j << " ";
            cout << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}