#include <bits/stdc++.h>
#define int long long
using namespace std;

int dis[5005];
int pre[5005];
struct edge
{
    int from, to, w;
};
vector <edge> E;

signed main()
{
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        E.push_back({a, b, c});
    }
    fill(dis, dis + 5005, 1e18);

/// n - 1 times
    for (int i = 1; i <= n - 1; i++) {
        for (auto it : E) {
            int f = it.from;
            int t = it.to;
            int w = it.w;
            if (dis[f] + w < dis[t]) {
                dis[t] = dis[f] + w;
                pre[t] = f;
            }
        }
    }

/// n-th time
    int v = 0;
    for (auto it : E) {
        int f = it.from;
        int t = it.to;
        int w = it.w;
        if (dis[f] + w < dis[t])
            v = t;
    }

/// have negative cycle
    if (!v) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    for (int i = 1; i <= n; i++)
        v = pre[v];
// We got into the cycle!

    int head = v;
    vector <int> ans;
    ans.push_back(head);
    v = pre[head];

    while (v != head) {
        ans.push_back(v);
        v = pre[v];
    }
    
    ans.push_back(head);
    reverse(ans.begin(), ans.end());
    for (int it : ans)
        cout << it << " ";
    cout << "\n";

    return 0;
}