#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int i;
    pair <int, int> arr[1005];

    int t;
    for (i=1;i<=n;i++) {
        cin >> t;
        arr[i].first=t;
        arr[i].second=i;
    }
    sort(arr+1, arr+n+1);

    int a,b,c,d;
    for (a=1;a<=n-3;a++) {
        for (b=a+1;b<=n-2;b++) {
            c=b+1, d=n;
            int tmp=arr[a].first+arr[b].first;
            while (c<d) {
                if (tmp+arr[c].first+arr[d].first==k) {
                    cout << arr[a].second << " " << arr[b].second << " "
                         << arr[c].second << " " << arr[d].second << "\n";
                    return 0;
                }
                if (tmp+arr[c].first+arr[d].first>k)
                    d--;
                else
                    c++;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
