// 倍增法求 LCA
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector<int> G[200005];
int dp[20][200005];
int dep[200005];

void dfs(int v, int p)
{
    dp[0][v] = p;
    for (int u:G[v]) {
        if (u == p) continue;
        dep[u] = dep[v] + 1;
        dfs(u, v);
    }
}

int query(int v, int step) /// CSES 1687
{
    for (int i=0; i<=18; i++) {
        if (step & (1 << i)) {
            step ^= 1 << i;
            v = dp[i][v];
        }
    }
    return v;
}

int LCA(int a, int b) /// CSES 1688
{
    if (dep[a] < dep[b])
        swap(a, b);
    int step = dep[a] - dep[b];
    for (int i=0; i<=18; i++)
        if (step & (1 << i))
            a = dp[i][a];
    
    if (a == b) return a;

    for (int i=18; i>=0; i--) {
        if (dp[i][a] != dp[i][b]) {
            a = dp[i][a];
            b = dp[i][b];
        }
    }

    return dp[0][a];
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q, i, j, tmp;
    cin >> n >> q;
    for (i=2; i<=n; i++) {
        cin >> tmp;
        G[tmp].push_back(i);
    }
    dep[1] = 0;
    dfs(1, 0);

    for (i=1; i<19; i++)
        for (j=1; j<=n; j++)
            dp[i][j] = dp[i-1][ dp[i-1][j] ];
    
    int a, b;
    while (q--){
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
    
    return 0;
}