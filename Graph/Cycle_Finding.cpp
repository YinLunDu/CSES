#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int dis[5005];
int pre[5005];
struct e
{
    int from, to, w;
};
vector <e> edges;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,i;
    int a,b,c;
    cin >> n >> m;
    for (i=1;i<=m;i++) {
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    
    fill(dis, dis+5005, 1e18);

// dis[1] = 0;

    for (i=0;i<n;i++) { /// n - 1 times
        for (auto it:edges) {
            int f=it.from;
            int t=it.to;
            int w=it.w;
            if (dis[f] + w < dis[t]) {
                dis[t] = dis[f] + w;
                pre[t] = f;
            }
        }
    }

    int node = 0;
    for (auto it:edges) {
        int f=it.from;
        int t=it.to;
        int w=it.w;
        if (dis[f] + w < dis[t])
            node = t;
    }

    if (!node) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    for (i=0;i<n;i++)
        node = pre[node];
    
    // We got into the cycle!

    int head = node;
    vector <int> ans;

    ans.push_back(head);
    node = pre[head];

    while (node != head) {
        ans.push_back(node);
        node = pre[node];
    }

    ans.push_back(head);

    reverse(ans.begin(), ans.end());
    for (auto it:ans)
        cout << it << " ";
    cout << "\n";

    return 0;
}