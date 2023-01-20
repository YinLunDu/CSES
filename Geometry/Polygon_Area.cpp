#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    int n;
    cin >> n;
    int i;
    pair <int, int> p[1005];
    for (i=1;i<=n;i++)
        cin >> p[i].first >> p[i].second;
    p[n+1]=p[1];
    int sum=0;
    for (i=1;i<=n;i++)
        sum+=p[i].first*p[i+1].second-p[i].second*p[i+1].first;

    cout << abs(sum) << "\n";
    return 0;
}
