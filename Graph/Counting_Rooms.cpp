#include <bits/stdc++.h>
#define int long long

using namespace std;

char input[1005][1005];
bool vis[1005][1005];
int n, m;

bool inside(int x, int y)
{
    return ((1<=x && x<=n && 1<=y && y<=m) ? 1 : 0);
}

void DFS(int x, int y)
{
    if (vis[x][y]) return;
    vis[x][y]=1;

    if (inside(x+1, y)) if (input[x+1][y]=='.') DFS(x+1, y);
    if (inside(x, y+1)) if (input[x][y+1]=='.') DFS(x, y+1);
    if (inside(x-1, y)) if (input[x-1][y]=='.') DFS(x-1, y);
    if (inside(x, y-1)) if (input[x][y-1]=='.') DFS(x, y-1);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(&vis[0][0], &vis[0][0]+1000*1000, false);
    cin >> n >> m;
    int i, j;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            cin >> input[i][j];
    int room=0;
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            if (vis[i][j]==1) continue;

            if (input[i][j]=='.') {
                DFS(i,j);
                room++;
            }
        }
    }
    cout << room << "\n";
    return 0;
}
