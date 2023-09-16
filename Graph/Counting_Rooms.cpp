#include <bits/stdc++.h>
#define int long long
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

char input[1005][1005];
bool vis[1005][1005];
int n, m;

bool inside(int x, int y)
{
    return ((1 <= x && x <= n && 1 <= y && y <= m) ? 1 : 0);
}

void dfs(int x, int y)
{
    if (vis[x][y]) return;
    vis[x][y] = true;

    if (inside(x+1, y)) if (input[x+1][y]=='.') dfs(x+1, y);
    if (inside(x, y+1)) if (input[x][y+1]=='.') dfs(x, y+1);
    if (inside(x-1, y)) if (input[x-1][y]=='.') dfs(x-1, y);
    if (inside(x, y-1)) if (input[x][y-1]=='.') dfs(x, y-1);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    loop(i, 1, n) loop(j, 1, m) cin >> input[i][j];

    int room = 0;
    loop(i, 1, n) {
        loop(j, 1, m) {
            if (vis[i][j]) continue;
            if (input[i][j] == '.') {
                dfs(i, j);
                room++;
            }
        }
    }
    
    cout << room << "\n";
    return 0;
}