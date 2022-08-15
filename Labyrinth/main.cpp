/**
5 8
########
#.A#...#
#.##.#B#
#......#
########
 **/
#include <bits/stdc++.h>

using namespace std;

char input[1005][1005];
bool vis[1005][1005];
pair <int, char> from[1005][1005];
int n, m;

bool inside(int x, int y)
{
    return ((1<=x && x<=n && 1<=y && y<=m) ? 1 : 0);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(&vis[0][0], &vis[0][0]+1000*1000, false);
    fill(&from[0][0], &from[0][0]+1000*1000, make_pair(0, '#'));
    cin >> n >> m;
    int i, j;
    int sX, sY, eX, eY;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            cin >> input[i][j];
            if (input[i][j]=='A') sX=i, sY=j;
            if (input[i][j]=='B') eX=i, eY=j;
        }
    input[eX][eY]='.';
    queue < pair<int, int> > q;
    q.push({sX, sY});
    vis[sX][sY]=1;
    int step=1;
    while (!q.empty()) {
        if (from[eX][eY].first!=0) break;

        int sz=q.size();
        for (i=1;i<=sz;i++) {
            pair <int, int> tmp=q.front();
            q.pop();
            int x=tmp.first, y=tmp.second;

            if (inside(x+1, y))
                if (input[x+1][y]=='.' && vis[x+1][y]==0) {
                    q.push({x+1, y});
                    vis[x+1][y]=1;
                    from[x+1][y]={step, 'D'};
                }
            if (inside(x, y+1))
                if (input[x][y+1]=='.' && vis[x][y+1]==0) {
                    q.push({x, y+1});
                    vis[x][y+1]=1;
                    from[x][y+1]={step, 'R'};
                }
            if (inside(x-1, y))
                if (input[x-1][y]=='.' && vis[x-1][y]==0) {
                    q.push({x-1, y});
                    vis[x-1][y]=1;
                    from[x-1][y]={step, 'U'};
                }
            if (inside(x, y-1))
                if (input[x][y-1]=='.' && vis[x][y-1]==0) {
                    q.push({x, y-1});
                    vis[x][y-1]=1;
                    from[x][y-1]={step, 'L'};
                }
        }
        step++;
    }
    if (from[eX][eY].first==0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << from[eX][eY].first << "\n";

    vector <char> ans;

    int x=eX, y=eY;

    for (i=1;i<=from[eX][eY].first;i++) {
        if (from[x][y].second=='U') ans.push_back(from[x][y].second), x++;
        if (from[x][y].second=='D') ans.push_back(from[x][y].second), x--;
        if (from[x][y].second=='L') ans.push_back(from[x][y].second), y++;
        if (from[x][y].second=='R') ans.push_back(from[x][y].second), y--;
    }
    int ans_sz=ans.size();
    for (i=ans_sz-1;i>=0;i--)
        cout << ans[i];
    cout << "\n";
/*
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            cout << from[i][j].second;
        }
        cout << "\n";
    }
*/
    return 0;
}
