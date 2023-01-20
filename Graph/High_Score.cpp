#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

struct e
{
    int a, b, w;
} edge[5002];
int dis[5002];
int pre[5002];
bool vis[5002];
vector <int> f[5002], b[5002];
bool ff[5002], bb[5002];

void gofront(int node)
{
    ff[node] = 1;
    for (auto it:f[node]) {
        if (!ff[it])
            gofront(it);
    }
}

void goback(int node)
{
    bb[node] = 1;
    for (auto it:b[node]) {
        if (!bb[it])
            goback(it);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int i;
    int x, y, c;
    for (i=1;i<=m;i++) {
        cin >> x >> y >> c;
        edge[i].a = x;
        edge[i].b = y;
        edge[i].w = c;
        f[x].push_back(y);
        b[y].push_back(x);
    }

    fill(dis, dis+5002, -1e18);
    dis[1]=0;
    for (i=1;i<=n-1;i++) {
        for (auto it:edge) {
            int from = it.a;
            int to = it.b;
            int weight = it.w;
            if (dis[from] != -1e18 && dis[from] + weight > dis[to]) {
                dis[to] = dis[from] + weight;
                pre[to] = from;
            }
        }
    }

/*
    for (i=1;i<=n;i++)
        cout << dis[i] << " ";
    cout << "\n";
*/
    vector <int> round;
    for (auto it:edge) {
        int from = it.a;
        int to = it.b;
        int weight = it.w;
        if (dis[from] != -1e18 && dis[from] + weight > dis[to])
            round.push_back(from);
    }

    for (i=1;i<=n-1;i++) {
        for (auto it:round)
            it = pre[it];
    }

    gofront(1);
    goback(n);

    for (auto it:round) {
        if (ff[it] && bb[it]) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << dis[n] << "\n";
    
    return 0;
}
/*
6 7
1 2 1
2 3 1
3 2 1
1 4 1
4 5 1
5 4 1
1 6 2
*/