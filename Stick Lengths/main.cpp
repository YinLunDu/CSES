#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[200005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,i;
    cin >> n;
    for (i=1;i<=n;i++)
        cin >> arr[i];

    sort(arr+1, arr+n+1);
    int idx=(n+1)/2;

    int sum=0;
    for (i=1;i<=n;i++)
        sum+=abs(arr[i]-arr[idx]);

    cout << sum << "\n";
    return 0;
}
