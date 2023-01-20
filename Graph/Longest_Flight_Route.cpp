#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector <int> G[100005];
vector <int> topo;
int vis[100005];
int dis[100005];
int pre[100005];
bool cycle;

void toposort(int node)
{
    if (vis[node] == 2) {cycle = true; return;}
    if (vis[node] == 1) return;

    vis[node] = 1;
    for (auto it:G[node])
        toposort(it);
    vis[node] = 2;
    topo.push_back(node);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    int i,a,b;
    for (i=1;i<=m;i++) {
        cin >> a >> b;
        G[a].push_back(b);
    }

    toposort(1);

    reverse(topo.begin(), topo.end());

    fill(dis, dis+100005, -1);
    dis[1] = 1;
    for (auto now:topo) {
        for (auto it:G[now]) {
            if (dis[now] + 1 > dis[it]) {
                dis[it] = dis[now] + 1;
                pre[it] = now;
            }
        }
    }

    if (dis[n] == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dis[n] << "\n";
        int idx = n;
        vector <int> ans;
        while (idx != 1) {
            ans.push_back(idx);
            idx = pre[idx];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        for (auto it:ans)
            cout << it << " ";
    }

    return 0;
}