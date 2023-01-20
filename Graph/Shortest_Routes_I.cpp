#include <bits/stdc++.h>
#define ll long long
#define W first
#define idx second

using namespace std;

///         dis idx
vector <pair<ll,ll>> G[100005];
ll dis[100005];
priority_queue <pair<ll, ll>, vector <pair<ll, ll>>, greater <pair<ll, ll>>> pq;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    ll i,a,b,c;
    for (i=1;i<=m;i++) {
        cin >> a >> b >> c;;
        G[a].push_back({c, b});
    }
    fill(dis, dis+100005, 100000000000000);
///        dis  idx
    pq.push({0, 1});
    dis[1]=0;
    while (pq.size()) {
        auto tmp=pq.top();
        pq.pop();

        if (dis[tmp.idx]!=tmp.W) continue;

        for (auto it:G[tmp.idx]) {
            if (dis[it.idx]>tmp.W+it.W) {
                dis[it.idx]=tmp.W+it.W;
                pq.push({dis[it.idx], it.idx});
            }
        }
    }

    for (i=1;i<=n;i++) {
        cout << dis[i] << " ";
    }
    cout << "\n";
    return 0;
}
