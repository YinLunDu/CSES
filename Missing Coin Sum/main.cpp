#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,i;
    cin >> n;
    vector <int> v;
    int tmp;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int sum=0;
    for (i=0;i<n;i++) {
        if (sum+1<v[i])
            break;
        sum+=v[i];
    }
    cout << sum+1 << "\n";
    return 0;
}
