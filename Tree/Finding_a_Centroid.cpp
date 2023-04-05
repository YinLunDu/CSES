#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int n;
vector<int> G[200005];
int ans = 1e18;

int dfs(int v, int p)
{
    int cnt = 0;
    bool flag = 1;
    for (int u:G[v]){
        if (u == p) continue;
        int tmp = dfs(u, v);
        if (tmp > (n/2)) flag = 0;
        cnt += tmp;
    }
    if ((n-1-cnt) > (n/2)) flag = 0;
    if (flag) ans = min(ans, v);
    return cnt+1;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int i;
    int a, b;
    for (i=1; i<=n-1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, -1);
    cout << ans << "\n";
    return 0;
}