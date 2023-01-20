#include <bits/stdc++.h>
#define int long long

using namespace std;

int mp[1005][1005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    int i,j;
    char ch;
    cin >> n >> q;

    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) {
            cin >> ch;
            if (i==1 && j==1) 
                mp[i][j]=(ch=='*' ? 1 : 0);
            else if (i==1)
                mp[i][j]=(ch=='*' ? 1 : 0)+mp[i][j-1];
            else if (j==1)
                mp[i][j]=(ch=='*' ? 1 : 0)+mp[i-1][j];
            else
                mp[i][j]=(ch=='*' ? 1 : 0)+mp[i][j-1]+mp[i-1][j]-mp[i-1][j-1];
        }
    }
    int x1,y1,x2,y2;
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << mp[x2][y2]-mp[x2][y1-1]-mp[x1-1][y2]+mp[x1-1][y1-1] << "\n";
    }

    return 0;
}

