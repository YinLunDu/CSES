// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define STL(x) for(auto &HEHE:x) cout << HEHE << " "; cout << "\n";
#define arr0(x,y) loop(HEHE,0,y-1) cout << x[HEHE] << " "; cout << "\n";
#define arr1(x,y) loop(HEHE,1,y) cout << x[HEHE] << " "; cout << "\n";
#define uni(x) (x).resize(unique((x).begin(),(x).end())-(x).begin());
#define unisort(x) sort((x).begin(),(x).end()); uni((x));
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void enter() {cout << "\n";}
ostream& operator <<(ostream& os, const pii& a) { os << "[" << a.F << ", " << a.S << "]"; return os; }
ostream& operator <<(ostream& os, const pair<int, pii>& a) { os << a.F << " : [" << a.S.F << ", " << a.S.S << "]"; return os; }
/// ------- Initialization End -------
struct DSU
{
    int N;
    vector <int> f, sz;
    DSU(int x) {
        init(x);
    }
    void init(int n) {
        N = n;
        f.resize(n + 1);
        iota(f.begin(), f.end(), 0);
        sz.assign(n + 1, 1);
    }
    int find(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }
};
vector <pair<int, pii>> E;
vector <pii> G[200005];
int vis[200005];
int depth[200005];
int lca[18][200005];
int mx_w[18][200005];

void dfs(int v, int p)
{
    vis[v] = true;
    depth[v] = depth[p] + 1;
    lca[0][v] = p;
    for (pii u : G[v]) {
        if (u.F == p) continue;
        mx_w[0][u.F] = u.S;
        dfs(u.F, v);
    }
}

void getLCA(int n)
{
    loop(i, 1, n) {
        if (!vis[i])
            dfs(i, 0);
    }
    loop(i, 1, 17) {
        loop(j, 1, n) {
            lca[i][j] = lca[i-1][lca[i-1][j]];
            mx_w[i][j] = max(mx_w[i-1][j], mx_w[i-1][lca[i-1][j]]);
        }
    }
}

int calc_mx_w(int v, int u)
{
    if (depth[v] < depth[u]) swap(v, u);
    int mx = 0;
    int step = depth[v] - depth[u];
    for (int i = 17; i >= 0; i--) {
        if (step & (1 << i)) {
            mx = max(mx, mx_w[i][v]);
            v = lca[i][v];
        }
    }
    if (v == u) return mx;
    for (int i = 17; i >= 0; i--) {
        if (lca[i][v] != lca[i][u]) {
            mx = max(mx, max(mx_w[i][v], mx_w[i][u]));
            v = lca[i][v];
            u = lca[i][u];
        }
    }
    mx = max(mx, max(mx_w[0][v], mx_w[0][u]));
    return mx;
}
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q, a, b;
    cin >> n >> m >> q;
    
    loop(i, 1, m) {
        cin >> a >> b;
        E.push_back({i, {a, b}});
    }
    sort(E.begin(), E.end());
    DSU D(n);
    loop(i, 0, m - 1) {
        int v = E[i].S.F;
        int u = E[i].S.S;
        int w = E[i].F;
        if (!D.same(v, u)) {
            G[v].push_back({u, w});
            G[u].push_back({v, w});
            D.merge(v, u);
        }
    }

    getLCA(n);

    while (q--) {
        cin >> a >> b;
        if (!D.same(a, b))
            cout << -1 << "\n";
        else
            cout << calc_mx_w(a, b) << "\n";
    }
    
    return 0;
}