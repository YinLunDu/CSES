#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;

bool mp[1005][1005];
int from[1005][1005];
int mvx[5]={-100, 1, 0, -1, 0};
int mvy[5]={-100, 0, 1, 0, -1};
bool visA[1005][1005];
bool visM[1005][1005];
int n, m;

bool inside(int a, int b)
{
    return (1<=a && a<=n && 1<=b && b<=m ? true : false);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    char ch;

    cin >> n >> m;

    queue < pair<int, int> > M;
    queue < pair<int, int> > A;    

    int i, j;
    int si, sj;
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            cin >> ch;
            if (ch=='#')
                mp[i][j]=0;
            else if (ch=='.')
                mp[i][j]=1;
            else if (ch=='A') {
                si=i, sj=j;
                A.push({i, j});
                visA[i][j]=1;
            } else {
                M.push({i, j});
                visM[i][j]=1;
            }
        }
    }

    if (si == 1 || si == n || sj == 1 || sj == m) {
        cout << "YES\n";
        cout << "0\n";
        return 0;
    }

    pii tmp;
    int x, y, sz;
    while (!A.empty()) {
        sz=M.size();
        while (sz--) {
            tmp = M.front();
            x=tmp.first, y=tmp.second;
            M.pop();

            for (int i=1;i<=4;i++) {
                if (inside(x+mvx[i], y+mvy[i]))
                    if (!visM[x+mvx[i]][y+mvy[i]] && mp[x+mvx[i]][y+mvy[i]] == 1) {
                        M.push({x+mvx[i], y+mvy[i]});
                        visM[x+mvx[i]][y+mvy[i]]=1;
                    }
            }
        }
        sz=A.size();
        while (sz--) {
            tmp = A.front();
            x=tmp.first, y=tmp.second;
            A.pop();

            for (int i=1;i<=4;i++) {
                if (inside(x+mvx[i], y+mvy[i]))
                    if (!visM[x+mvx[i]][y+mvy[i]] && !visA[x+mvx[i]][y+mvy[i]] && mp[x+mvx[i]][y+mvy[i]] == 1) {

                        A.push({x+mvx[i], y+mvy[i]});
                        visA[x+mvx[i]][y+mvy[i]] = 1;
                        from[x+mvx[i]][y+mvy[i]] = i;

                        if (x+mvx[i] == 1 || x+mvx[i] == n || y+mvy[i] == 1 || y+mvy[i] == m) {
                            vector <int> ans;
                            int nowx = x+mvx[i], nowy = y+mvy[i];

                            while (nowx != si || nowy != sj) {
                                ans.push_back(from[nowx][nowy]);
                                if (from[nowx][nowy]==1)
                                    nowx--;
                                else if (from[nowx][nowy]==2)
                                    nowy--;
                                else if (from[nowx][nowy]==3)
                                    nowx++;
                                else
                                    nowy++;
                            }

                            reverse(ans.begin(), ans.end());
/*
                            for (i=1;i<=n;i++) {
                                for (j=1;j<=m;j++) {
                                    cout << from[i][j] << " ";
                                }
                                cout << "\n";
                            }
*/
                            cout << "YES\n";
                            cout << ans.size() << "\n";
                            for (auto it:ans) {
                                if (it == 1)
                                    cout << "D";
                                else if (it == 2)
                                    cout << "R";
                                else if (it == 3)
                                    cout << "U";
                                else
                                    cout << "L";
                            }
                            cout << "\n";
                            return 0;
                        }
                    }
            }
        }
        
    }
    cout << "NO\n";
    
    return 0;
}