#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> G[200005];
bool vis[200005];
int deg[200005];
queue <ll> q;
vector <ll> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    ll i,a,b;
    fill(deg, deg+200005, 0);
    fill(vis, vis+200005, false);

    for (i=1;i<=m;i++) {
        cin >> a >> b;
        G[a].push_back(b);
        deg[b]++;
    }

    for (i=1;i<=n;i++)
        if (deg[i]==0)
            q.push(i);

    ll tmp;
    bool legal=true;
    ans.clear();
    while (q.size()>0) {
        tmp=q.front();
        q.pop();
        ans.push_back(tmp);
        vis[tmp]=1;
        for (auto x:G[tmp]) {
            if (!vis[x]) {
                if (deg[x]==1)
                    q.push(x);
                deg[x]--;
            } else {
                legal=false;
            }
        }
    }

    if (!legal || (ll)ans.size()!=n)
        cout << "IMPOSSIBLE\n";
    else {
        for (auto x:ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
