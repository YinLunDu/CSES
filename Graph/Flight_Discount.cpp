#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector < pii > G[200005];
int dis[200005][2];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(&dis[0][0], &dis[0][0]+200005*2, 1e18);

    int n, m, i;
    cin >> n >> m;
    int a, b, c;
    for (i=1;i<=m;i++) {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    priority_queue < pair <int, pair<int, int>>,
                     vector <pair<int, pair<int, int>>>,
                     greater <pair<int, pair<int, int>>> > pq;

    dis[1][0] = 0;
    dis[1][1] = 0;
    pq.push({0, {1, 0}});
    while (!pq.empty()) {
        int w = pq.top().first;
        int node = pq.top().second.first;
        int use = pq.top().second.second;

        pq.pop();

        if (dis[node][use] != w)
            continue;

        for (auto it:G[node]) {
            if (w + it.second < dis[it.first][use]) {
                dis[it.first][use] = w + it.second;
                pq.push({dis[it.first][use], {it.first, use}});
            }

            if (!use && w + (it.second/2) < dis[it.first][1]) {
                dis[it.first][1] = w + (it.second/2);
                pq.push({dis[it.first][1], {it.first, 1}});
            }
        }
    }
    cout << dis[n][1] << "\n";

    return 0;
}