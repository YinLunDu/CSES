#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

pii arr[200005];

bool cmp(pii x, pii y)
{
    return x.second < y.second;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i;
    cin >> n;
    for (i=1;i<=n;i++)
        cin >> arr[i].first >> arr[i].second;
    
    sort(arr+1, arr+n+1, cmp);
    int end = 0, cnt = 0;
    for (i=1;i<=n;i++) {
        if (end <= arr[i].first) {
            end = arr[i].second;
            cnt++;
        }
    }
    cout << cnt << "\n";
    
    return 0;
}