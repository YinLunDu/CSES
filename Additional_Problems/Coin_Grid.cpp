// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define STL(x) for (auto &HEHE : x) cout << HEHE << " "; cout << "\n";
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void ent() {cout << "\n";}

const int mod = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

bool mp[105][105];

struct info
{
    int v, u, rev, cap;
};
vector <info> E;
vector <int> G[205];
int lvl[205];
int p[205];

int dinic(int S, int T)
{
    int ans = 0;
    while (true) {
        fill(lvl, lvl + 205, INF);
        lvl[S] = 0;
        queue <int> Q;
        Q.push(S);
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (int id : G[v]) {
                if (E[id].cap > 0 && lvl[E[id].u] == INF) {
                    lvl[E[id].u] = lvl[v] + 1;
                    Q.push(E[id].u);
                    p[E[id].u] = id;
                }
            }
        }
        if (lvl[T] == INF)
            break;
        int now = T, mncap = INF;
        while (now != S) {
            mncap = min(mncap, E[p[now]].cap);
            now = E[p[now]].v;
        }
        ans += mncap;
        now = T;
        while (now != S) {
            E[p[now]].cap -= mncap;
            E[E[p[now]].rev].cap += mncap;
            now = E[p[now]].v;
        }
    }
    return ans;
}

bool vis[205];
void bfs_empty_pipe(int S)
{
    queue <int> Q;
    Q.push(S);
    vis[S] = 1;
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int id : G[v]) {
            if (!vis[E[id].u] && E[id].cap > 0) {
                vis[E[id].u] = 1;
                Q.push(E[id].u);
            }
        }
    }
}

void add_pipe(int v, int u, int cap)
{
    G[v].push_back(E.size());
    G[u].push_back(E.size() + 1);
    E.push_back({v, u, (int)E.size() + 1, cap});
    E.push_back({u, v, (int)E.size() - 1, 0});
}
signed main()
{
    IOS
    
    int n;
    cin >> n;

    char ch;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ch;
            if (ch == 'o')
                mp[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
        add_pipe(0, i, 1);
    for (int i = 1; i <= n; i++)
        add_pipe(100 + i, 100 + n + 1, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mp[i][j]) {
                // i <-> j + 100
                add_pipe(i, j + 100, INF);
            }
        }
    }

    int ans = dinic(0, 100 + n + 1);
    cout << ans << "\n";
    bfs_empty_pipe(0);

    for (auto id : E) {
        if (vis[id.v] && !vis[id.u] && (id.v == 0 || id.u == 100 + n + 1) && id.cap == 0) {
            if (id.v == 0)
                cout << 1 << " " << id.u << "\n";
            else
                cout << 2 << " " << id.v - 100 << "\n";
        }
    }
    
    return 0;
}