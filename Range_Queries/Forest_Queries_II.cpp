#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;

bool mp[1005][1005];
int bit[1005][1005];

void update(int x, int y, int val)
{
    while (x <= 1000) {
        int idx = y; /// y座標 每一次都要從 y 開始
        while (idx <= 1000) {
            bit[x][idx] += val;
            idx += (idx & -idx);
        }
        x += (x & -x);
    }
    return;
}

int query(int x, int y)
{
    int sum=0;
    while (x > 0) {
        int idx = y; /// y座標 每一次都要從 y 開始
        while (idx > 0) {
            sum += bit[x][idx];
            idx -= (idx & -idx);
        }
        x -= (x & -x);
    }
    return sum;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    int i, j;
    char ch;
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) {
            cin >> ch;
            if (ch == '*') {
                mp[i][j]=1;
                update(i, j, 1);
            } else {
                mp[i][j]=0;
            }
        }
    }

    int v, a, b, c, d;
    while (q--) {
        cin >> v;
        if (v==1) {
            cin >> a >> b;
            if (mp[a][b]) {
                update(a, b, -1);
                mp[a][b]=0;
            } else {
                update(a, b, 1);
                mp[a][b]=1;
            }
        } else {
            cin >> a >> b >> c >> d;
            cout << query(c, d) - query(a-1, d) - query(c, b-1) + query(a-1, b-1) << "\n";
        }
    }
    
    return 0;
}