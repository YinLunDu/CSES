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

    int n, k, i;
    cin >> n >> k;
    for (i=1;i<=n;i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr+1, arr+n+1, cmp);

    int cnt = 0;
    multiset <int> s;
    for (i=1;i<=k;i++)
        s.insert(0);
    for (i=1;i<=n;i++) {
        auto it = s.upper_bound(arr[i].first);
        if (it == s.begin()) continue;
        it = prev(it);

        s.erase(it);
        s.insert(arr[i].second);
        cnt++;
    }
    cout << cnt << "\n";
    
    return 0;
}