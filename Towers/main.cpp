#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    multiset <int> s;
    int n, tmp, cnt=0, i;
    cin >> n;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        if (s.empty()) {
            s.insert(tmp);
            cnt++;
        } else {
            auto it=s.upper_bound(tmp);
            if (it==s.end()) {
                s.insert(tmp);
                cnt++;
            } else {
                s.erase(it);
                s.insert(tmp);
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
