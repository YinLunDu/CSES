/**
 * @brief 前啜和
 * 
 */
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int mod[200005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x,i,sum=0;
    cin >> n;
    
    mod[0]++; /// 從第一個開始也要算
    for (i=1;i<=n;i++) {
        cin >> x;
        sum += x;
        sum = (sum % n + n) % n;
        mod[sum]++;
    }

    int ans=0;
    for (i=0;i<n;i++)
        ans += (mod[i] - 1) * mod[i] / 2;
    
    cout << ans << "\n";

    return 0;
}