#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int dp[20][10]; /// i 位數 尾數是 j

void init()
{
    for (int j=0; j<=9; j++)
        dp[1][j] = 1;
    for (int i=2; i<=18; i++) {
        for (int now=0; now<=9; now++) {
            for (int pre=0; pre<=9; pre++) {
                if (now != pre)
                    dp[i][now] += dp[i-1][pre];
            }
        }
    }
}

int calc(int x)
{
    if (x == 0) return 0;
    int arr[20], len = 0;
    while (x > 0) arr[++len] = x % 10, x /= 10;

/// 計算 len 位數 的數
    int cnt = 0, pre = -1;
    for (int idx=len; idx>=1; idx--) {
        for (int now=(idx == len); now<arr[idx]; now++) {
            if (now != pre)
                cnt += dp[idx][now];
        }
        if (arr[idx] == pre)
            break;
        pre = arr[idx];
        if (idx == 1)
            cnt++;
    }
/// 計算 小於 len 位數 的數
    for (int i=1; i<len; i++) {
        for (int j=1; j<=9; j++) {
            cnt += dp[i][j];
        }
    }
    return cnt;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    init();
    cin >> a >> b;
    cout << calc(b) - calc(a-1) + (a == 0 ? 1 : 0) << "\n";
    
    return 0;
}