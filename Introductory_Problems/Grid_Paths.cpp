#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int ans = 0;
bool vis[10][10];
int mvx[4] = {0, 0, -1, 1};
int mvy[4] = {1, -1, 0, 0};
int arr[50];

void dfs(int x, int y, int idx)
{
    if (x == 1 && y == 7) {
        if (idx == 48) ans++;
        return;
    }
    if (idx == 48)
        return;
    
    if (!vis[x+1][y] && !vis[x-1][y] && vis[x][y+1] && vis[x][y-1])
        return;
    if (!vis[x][y+1] && !vis[x][y-1] && vis[x+1][y] && vis[x-1][y])
        return;
    
    if (0 <= arr[idx] && arr[idx] <= 3) {
        pii p = {x + mvx[ arr[idx] ], y + mvy[ arr[idx] ]};
        if (!vis[p.first][p.second]) {
            vis[p.first][p.second] = 1;
            dfs(p.first, p.second, idx+1);
            vis[p.first][p.second] = 0;
        }
    } else {
        for (int i=0; i<=3; i++) {
            pii p = {x + mvx[i], y + mvy[i]};
            if (!vis[p.first][p.second]) {
                vis[p.first][p.second] = 1;
                dfs(p.first, p.second, idx+1);
                vis[p.first][p.second] = 0;
            }
        }    
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int i, j;

    cin >> s;
    for (i=0; i<=47; i++) {
        if (s[i] == 'D')
            arr[i] = 0;
        else if (s[i] == 'U')
            arr[i] = 1;
        else if (s[i] == 'L')
            arr[i] = 2;
        else if (s[i] == 'R')
            arr[i] = 3;
        else
            arr[i] = -1;
    }
    
    for (i=0; i<=8; i++)
        for (j=0; j<=8; j++)
            if (i == 0 || i == 8 || j == 0 || j == 8)
                vis[i][j] = 1;

    vis[1][1] = 1;
    dfs(1, 1, 0);
    cout << ans << "\n";
    
    return 0;
}