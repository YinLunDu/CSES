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
    pre[0] = 1;
    int now_pre = 0;
    int cnt = 0;
/**
     [l, r] = [0, r]  - [0, l-1]
        x   = now_pre -   tar
     So, we need to find (now_pre - x)
**/
    for (i=1;i<=n;i++) {
        now_pre += arr[i];
        int tar = now_pre-x;
        if (pre.find(tar) != pre.end())
            cnt += pre[tar];
        pre[now_pre]++;
    }

    cout << cnt << "\n";
    return 0;
}
