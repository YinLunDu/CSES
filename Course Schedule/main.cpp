#include <bits/stdc++.h>
#define int long long

using namespace std;

vector <int> G[100005];
int deg[100005];
bool vis[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int i, a, b;

    fill(deg, deg+100005, 0);
    fill(vis, vis+100005, 0);

    for (i=1;i<=m;i++) {
        cin >> a >> b;
        G[a].push_back(b);
        deg[b]++;
    }

    vector <int> ans;

    queue <int> q;
    for (i=1;i<=n;i++)
        if (deg[i]==0) {
            q.push(i);
            ans.push_back(i);
        }


    while (!q.empty()) {
        int tmp=q.front();
        q.pop();
        for (auto it:G[tmp]) {
            if (vis[it]) continue;
            deg[it]--;
            if (deg[it]==0) {
                ans.push_back(it);
                q.push(it);
                vis[it]=1;
            }
        }
    }
    if (ans.size()==n) {
        for (auto it:ans)
            cout << it << " ";
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }


    return 0;
}
