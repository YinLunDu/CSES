#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> G[100005];
bool vis[100005];
vector <ll> town;

void DFS(ll node)
{
    vis[node]=1;
    for (auto i:G[node]) {
        if (vis[i]==0)
            DFS(i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,a,b;
///      town   road
    cin >> n >> m;
    fill(vis, vis+100005, 0);
    ll i;
    for (i=1;i<=m;i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ll ans=0;
    for (i=1;i<=n;i++) {
        if (vis[i]) continue;

        DFS(i);
        town.push_back(i);
        ans++;
    }
/*
    for (i=1;i<=n;i++) {
        for (auto x:G[i])
            cout << x << " ";
        cout << "\n";
    }
*/
    cout << ans-1 << "\n";

    ll sz=town.size();
    for (i=0;i<=sz-2;i++)
        cout << town[i] << " " << town[i+1] << "\n";
    return 0;
}
