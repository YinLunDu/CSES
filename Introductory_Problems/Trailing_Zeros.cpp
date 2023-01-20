#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans=0;
    int res=5;
    while (res<=n) {
        ans+=n/res;
        res*=5;
    }
    cout << ans << "\n";
    return 0;
}
