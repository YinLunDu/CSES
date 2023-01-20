#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;

vector <int> G[100005];
int p[100005]; /// parent of each node
bool vis[100005];
int two, cyclenode;

bool dfs(int node, int parent)
{
    for (auto u:G[node]) {
        if (!vis[u]) {
            p[u]=node;
            vis[u]=1;
            if (dfs(u, node))
                return true;
        } else if (u != parent) {
            two = u;
            cyclenode = node;
            return true;
        } else {
            continue;
        }
        
    }
    return false;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    int a,b;
    int i;
    for (i=1;i<=m;i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (i=1;i<=n;i++) {
        if (!vis[i]) {
            vis[i]=1;
            if (dfs(i, 0)) {
                vector <int> ans;
                ans.push_back(two);
                while (cyclenode != two) {
                    ans.push_back(cyclenode);
                    cyclenode = p[cyclenode];
                }
                ans.push_back(two);
                cout << ans.size() << "\n";
                for (auto it:ans)
                    cout << it << " ";
                cout << "\n";
                return 0;
            }
        }
    }
    
    cout << "IMPOSSIBLE\n";
    
    return 0;
}