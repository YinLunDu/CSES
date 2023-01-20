#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector <pii> G[200005];
int dis[200005];
int cnt[200005];
int minf[200005];
int maxf[200005];
const int MOD = 1e9+7;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(dis, dis+200005, 1e18);
    fill(minf, minf+200005, 1e18);
    fill(maxf, maxf+200005, -1e18);

    int n, m, i;
    cin >> n >> m;
    int a, b, c;
    for (i=1;i<=m;i++) {
        cin >> a >> b >> c;
        G[a].push_back({c, b});
    }

    priority_queue < pii, vector <pii>, greater<pii> > pq;
    pq.push({0, 1});
    dis[1] = 0;
    cnt[1] = 1;
    minf[1] = 0;
    maxf[1] = 0;

    while (!pq.empty()) {
        int w = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it:G[node]) {
            int nextweight = it.first;
            int nextnode = it.second;
            if (w + nextweight == dis[nextnode]) {
                cnt[nextnode] = (cnt[nextnode] + cnt[node]) % MOD;
                minf[nextnode] = min(minf[nextnode], minf[node] + 1);
                maxf[nextnode] = max(maxf[nextnode], maxf[node] + 1);
            } else if (w + nextweight < dis[nextnode]) {
                dis[nextnode] = w + nextweight;
                cnt[nextnode] = cnt[node];
                minf[nextnode] = minf[node] + 1;
                maxf[nextnode] = maxf[node] + 1;
                pq.push({dis[nextnode], nextnode});
            }
        }
    }
/*
    for (i=1;i<=n;i++)
        cout << dis[i] << " ";
    cout << "\n";
    for (i=1;i<=n;i++)
        cout << cnt[i] << " ";
    cout << "\n";
    for (i=1;i<=n;i++)
        cout << minf[i] << " ";
    cout << "\n";
    for (i=1;i<=n;i++)
        cout << maxf[i] << " ";
    cout << "\n";
*/
    cout << dis[n] << " " << cnt[n] % MOD << " " << minf[n] << " " << maxf[n] << "\n";


    return 0;
}