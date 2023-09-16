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

vector <int> G[1 << 15];
vector <int> ans;

void dfs(int v)
{
    while (!G[v].empty()) {
        int u = G[v].back();
        G[v].pop_back();
        dfs(u);
    }
    ans.push_back(v & 1);
}

signed main()
{
    IOS
    
    int n;
    cin >> n;
    if (n == 1) {
        cout << "10\n";
        return 0;
    }

    for (int i = 0; i < (1 << (n - 1)); i++) {
        G[i].push_back((i << 1) & ((1 << (n - 1)) - 1));
        G[i].push_back(((i << 1) | 1) & ((1 << (n - 1)) - 1));
    }
    
    dfs(0);
    reverse(ans.begin(), ans.end());

/// output (n - 2) times '0'
    for (int i = 1; i <= n - 2; i++)
        cout << 0;
    for (int it : ans)
        cout << it;
    cout << "\n";
    
    return 0;
}