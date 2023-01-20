#include <bits/stdc++.h>
#define int long long

using namespace std;

int arr[200005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int i;
    int sum=0;
    int mx=0;
    for (i=1;i<=n;i++) {
        cin >> arr[i];
        sum+=arr[i];
        mx=max(mx, arr[i]);
    }
    
    if (mx >= sum-mx) {
        cout << 2*mx << "\n";
    } else {
        cout << sum << "\n";
    }
    return 0;
}