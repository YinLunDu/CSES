// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define STL(x) for(auto &HEHE:x) cout << HEHE << " "; cout << "\n";
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void enter() {cout << "\n";}
/// ------- Initialization End -------

const int INF = 1e15;
struct edge
{
    int v, u, rev, cap;
};

vector <edge> E;
vector <int> G[505];
vector <int> ans;
int lvl[505];
int p[505];
int n, m;
int vis[505];

bool dfs(int v)
{
    if (vis[v]) return false;
    ans.push_back(v);
    if (v == n)
        return true;
    
    vis[v] = true;
    for (int id : G[v]) {
        if (!E[id].cap && id % 2 == 0) {
            if (dfs(E[id].u)) {
                E[id].cap = 1;
                vis[v] = false;
                return true;
            }
        }
    }
    ans.pop_back();
    vis[v] = false;
    return false;
}

signed main()
{
    IOS
    
    int a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        c = 1;
        E.push_back({a, b, 2 * i + 1, c});
        E.push_back({b, a, 2 * i, 0});
        G[a].push_back(2 * i);
        G[b].push_back(2 * i + 1);
    }

    int flow = 0;
    
    while (true) {
        queue <int> Q;
        fill(lvl, lvl + 505, INF);
        Q.push(1);
        lvl[1] = 0;
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (int id : G[v]) {
                if (E[id].cap > 0 && lvl[E[id].u] == INF) {
                    lvl[E[id].u] = lvl[v] + 1;
                    p[E[id].u] = id;
                    Q.push(E[id].u);
                }
            }
        }
        
        if (lvl[n] == INF) break;

        int v = n, mincap = INF;
        while (v != 1) {
            mincap = min(mincap, E[p[v]].cap);
            v = E[p[v]].v;
        }

        flow += mincap;
        v = n;
        while (v != 1) {
            E[p[v]].cap -= mincap;
            E[E[p[v]].rev].cap += mincap;
            v = E[p[v]].v;
        }
    }
    cout << flow << "\n";
    for (int i = 1; i <= flow; i++) {
        ans.clear();
        dfs(1);
        cout << ans.size() << "\n";
        for (int it : ans)
            cout << it << " ";
        cout << "\n";
    }
    
    return 0;
}