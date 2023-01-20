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
    
    int cnt=0;
    int p=1;
    int sum=0;
    for (i=1;i<=n;i++) {
        sum += arr[i];
        while (sum > x && p <= i) {
            sum -= arr[p];
            p++;
        }
        if (sum == x)
            cnt++;
    }
    cout << cnt << "\n";

    return 0;
}
