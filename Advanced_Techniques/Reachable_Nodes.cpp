#pragma GCC optimize("Ofast,unroll-loops,O3")
#pragma GCC target("popcnt")
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
void ent() {cout << "\n";}

const int mod = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

vector <int> G[50005];
array <bitset<50005>, 50005> dp;
int in[50005];

signed main()
{
    IOS
    
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        in[b]++;
    }

    queue <int> Q;
    vector <int> order;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0)
            Q.push(i);
    }

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        order.push_back(v);
        for (int u : G[v]) {
            in[u]--;
            if (in[u] == 0)
                Q.push(u);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        int v = order[i];
        dp[v][v] = 1;
        for (int u : G[v])
            dp[v] |= dp[u];
    }

    for (int i = 1; i <= n; i++) {
        int x = dp[i].count();
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}