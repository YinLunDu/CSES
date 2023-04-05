#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
 
const int mod = 1e9+7;
 
vector<int> G[25];
int dp[22][1 << 22];
 
int f(int now, int mask)
{
    if (~dp[now][mask])
        return dp[now][mask];
    
    int res = 0;
    for (int pre:G[now])
        if (mask & (1 << pre)) {
            res += f(pre, mask ^ (1 << now));
            res %= mod;
        }
    return dp[now][mask] = res;
}
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m, i, j;
 
    for (i=0; i<=21; i++)
        for (j=0; j<=(1 << 21); j++)
            dp[i][j] = -1;
    
    cin >> n >> m;
    int a, b;
    
    for (i=1; i<=m; i++) {
        cin >> a >> b;
        a--, b--;
        if (a != b)
            G[b].push_back(a);
    }
    
    for (i=1; i<n; i++)
        dp[i][1 << i] = 0;
    
    dp[0][1] = 1;
 
    cout << f(n - 1, (1 << n) - 1) << "\n";
    
    return 0;
}