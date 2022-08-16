#include <bits/stdc++.h>
#define int long long

using namespace std;

int arr[200005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x,i;
    cin >> n >> x;
    for (i=1;i<=n;i++)
        cin >> arr[i];
    map <int, int> pre;
    pre[0]=1;
    int now_pre=0;
    int ans=0;
    for (i=1;i<=n;i++) {
        now_pre+=arr[i];
        int tar=now_pre-x;
        if (pre.find(tar)!=pre.end())
            ans+=pre[tar];
        pre[now_pre]++;
    }
    cout << ans << "\n";
    return 0;
}
