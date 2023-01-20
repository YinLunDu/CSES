#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector<int> G[100005];
int cnt[100005];
const int MOD = 1e9+7;
vector<int> topo;
int vis[100005];
bool cycle;

void toposort(int node)
{
    if (vis[node] == 1) {cycle = 1; return;}
    if (vis[node] == 2) {return;}

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

    int n, m;
    int i, a, b;
    cin >> n >> m;
    for (i=1;i<=m;i++) {
        cin >> a >> b;
        G[a].push_back(b);
    }

    toposort(1);
    reverse(topo.begin(), topo.end());
    cnt[1] = 1;

    for (auto now:topo) {
        for (auto it:G[now]) {
            cnt[it] = (cnt[it] + cnt[now]) % MOD;
        }
    }

    cout << cnt[n] % MOD << "\n";
    
    return 0;
}
/*
3 4
1 3
1 2
2 3
3 4
*/