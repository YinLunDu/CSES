#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> G[100005];
bool vis[100005];
int color[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,i,a,b;
    cin >> n >> m;

    fill(color, color+100005, -1);

    for (i=1;i<=m;i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    fill(vis, vis+100005, 0);

    for (i=1;i<=n;i++) {
        if (vis[i]==1) continue;
        ///       index color
        queue <pair <ll,ll>> q;
        q.push({i,1});
        vis[i]=1;
        color[i]=1;
        while (q.size()>0) {
            pair <ll,ll> tmp=q.front();
            q.pop();

            int next_color;
            if (tmp.second==1) next_color=2; else next_color=1;

            for (auto next:G[tmp.first]) {

                if (vis[next]==1) {
                    if (color[next]!=next_color) {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                } else {
                    q.push({next, next_color});
                    vis[next]=1;
                    color[next]=next_color;
                }
            }
        }
    }

    for (i=1;i<=n;i++)
        cout << color[i] << " ";
    cout << "\n";
    return 0;
}
