#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> G[200005];
ll dp[200005]; bool pointed[200005];
ll ans=0;

void DFS(ll node, ll parent)
{
    //cout << node << " ";
    pair <ll, ll> mx={0,0};

    for (auto it:G[node]) {
        if (it==parent) continue;

        DFS(it, node);

        if (dp[it]>mx.first)
            mx={dp[it], mx.first};
        else if (dp[it]>mx.second)
            mx={mx.first, dp[it]};
    }

    dp[node]=mx.first+1;
    ans=max(ans, mx.first+mx.second);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,i,a,b;
    fill(pointed, pointed+200005, 0);
    cin >> n;
    for (i=1;i<=n-1;i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    fill(dp, dp+200005, 0);

    DFS(1,1);

    cout << ans << "\n";
    return 0;
}
