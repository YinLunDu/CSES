#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

bool mp[9][9];
bool mx[9], my[9], dx[18], dy[18]; /// dx : x+y  dy : x-y
int ans = 0;

void backtrack(int x, int y, int cnt)
{
    if (x == 9) {
        x = 1;
        y++;
    }

    if (y == 9) {
        if (cnt == 8)
            ans++;
        return;
    }
    
    if (!mp[x][y] && !mx[x] && !my[y] && !dx[(x+y)%17] && !dy[(x-y+17)%17]) {
        mx[x] = my[y] = dx[(x+y)%17] = dy[(x-y+17)%17] = 1;
        backtrack(x+1, y, cnt+1);
        mx[x] = my[y] = dx[(x+y)%17] = dy[(x-y+17)%17] = 0;
    }

    backtrack(x+1, y, cnt);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i, j;
    char c;

    for (i=1; i<=8; i++) {
        for (j=1; j<=8; j++) {
            cin >> c;
            if (c == '*')
                mp[i][j] = 1;
        }
    }
    backtrack(1, 1, 0);

    cout << ans << "\n";

    return 0;
}