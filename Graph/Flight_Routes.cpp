/**
 * @brief Dijkstra
 *        利用 vis[] 紀錄 每個點的 入點次數
 *        如果超過 k 就不用遍歷了
 * 
 */
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

vector <pii> G[200005];
int vis[200005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, a, b, c;
    cin >> n >> m >> k;
    loop(i, 1, m) {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }
    priority_queue <pii, vector <pii>, greater <pii>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        int w = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (vis[v] >= k)
            continue;
        
        vis[v]++;
        if (v == n)
            cout << w << " ";

        for (pii u : G[v])
            pq.push({w + u.second, u.first});
    }
    cout << "\n";

    return 0;
}