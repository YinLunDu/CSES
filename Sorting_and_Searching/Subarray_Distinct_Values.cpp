#include <bits/stdc++.h>
#define int long long

using namespace std;

int arr[200005];
map <int, int> mp;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,i;
    cin >> n >> k;
    for (i=1;i<=n;i++) {
        cin >> arr[i];
        mp[arr[i]] = 0;
    }

    int cnt = 0;
    
    int l=1, r=1;
    mp[arr[1]]++;
    cnt++;
    
    int distinct = 1;
    while (r+1 <= n) {
        int now = arr[r+1];
        if (mp[now] != 0) {
            mp[now]++;
            r++;
            cnt += r-l+1;
            //cout << l << " " << r << "\n";
        } else if (distinct + 1 <= k) {
            mp[now]++;
            r++;
            distinct++;
            cnt += r-l+1;
            //cout << l << " " << r << "\n";
        } else {
            if (mp[arr[l]] == 1) distinct--;
            mp[arr[l]]--;
            l++;
        }
    }
    cout << cnt << "\n";

    return 0;
}
