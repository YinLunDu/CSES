#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> G[100005];
bool vis[100005];
ll pre[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,i,a,b;
    cin >> n >> m;
    for (i=1;i<=m;i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    fill(vis, vis+100005, 0);

    queue <ll> q;
    q.push(1);
    bool success=false;
    while (q.size()>0) {
        ll tmp=q.front();
        q.pop();
        if (tmp==n) {success=1; break;}

        for (auto it:G[tmp]) {
            if (vis[it]==1) continue;
            q.push(it);
            vis[it]=1;
            pre[it]=tmp;
        }
    }
    if (success) {
        vector <ll> ans;
        ll idx=n;
        while (idx!=1) {
            ans.push_back(idx);
            idx=pre[idx];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto x:ans)
            cout << x << " ";
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
