#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;

int n,k;
int arr[200005];

bool check(int x)
{
    int i, sum=0, cnt=1;
    for (i=1;i<=n;i++) {
        if (sum + arr[i] <= x)
            sum+=arr[i];
        else if (arr[i] > x) {
            return false;
        } else {
            cnt++;
            sum=arr[i];
        }
    }
    if (cnt > k) return false;
    else return true;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    int i;
    for (i=1;i<=n;i++)
        cin >> arr[i];
    
    int l=1, r=1e18;
    while (l<=r) {
        int mid=(l+r)/2;
        if (check(mid))
            r=mid-1;
        else
            l=mid+1;
    }
    cout << l << "\n";
    
    return 0;
}