/**
 * @brief Dijkstra
 *        利用 vis[] 紀錄 每個點的 入點次數
 *        如果超過 k 就不用遍歷了
 * 
 */
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector <pii> G[200005];
int vis[200005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k,i;
    
    cin >> n >> m >> k;
    int a, b, c;
    for (i=1;i<=m;i++) {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    fill(vis, vis+200005, 0);

    priority_queue < pii, vector <pii>, greater <pii> > pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int w = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (vis[node] >= k)
            continue;
        vis[node]++;
        
        if (node == n)
            cout << w << " ";

        for (auto it:G[node])
            pq.push({w + it.second, it.first});
    }
    cout << "\n";

    return 0;
}