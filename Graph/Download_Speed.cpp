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

const int INF = 1e15;

struct edge
{
    int v, u, rev, cap;
};

edge E[2 * 1005];
vector <int> G[505];
int lvl[505];
int p[505];

signed main()
{
    
    int n, m;
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        E[2 * i]     = {a, b, 2 * i + 1, c};
        E[2 * i + 1] = {b, a, 2 * i    , 0};
        G[a].push_back(2 * i);
        G[b].push_back(2 * i + 1);
    }

    int ans = 0;

    int s = 1, t = n;

    while (true) {
        fill(lvl, lvl + n + 1, 1e15);

        lvl[s] = 0;

        queue <int> Q;
        Q.push(s);

        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (int i : G[v]) {
                if (E[i].cap > 0 && lvl[E[i].u] > 1e10) {
                    lvl[E[i].u] = lvl[v] + 1;
                    p[E[i].u] = i;
                    Q.push(E[i].u);
                }
            }
        }

        if (lvl[t] > 1e10) break;


        int water = INF, v = t;
        while (v != s) {
            water = min(water, E[p[v]].cap);
            v = E[p[v]].v;
        }

        ans += water;
        // dbg(water);
        // loop(i, 0, 2 * m - 1) cout << E[i].cap << " ";
        // cout << "\n";

        v = t;
        while (v != s) {
            E[p[v]].cap -= water;
            E[E[p[v]].rev].cap += water;
            v = E[p[v]].v;
        }
    }
    cout << ans << "\n";
    
    return 0;
}