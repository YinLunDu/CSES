#include <bits/stdc++.h>
#define int long long

using namespace std;

multiset <int> s;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    int i,tmp;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        s.insert(tmp);
    }
    for (i=1;i<=m;i++) {
        cin >> tmp;
        auto it=s.lower_bound(tmp);
        if (s.empty())
            cout << "-1\n";
        else if (*it==tmp) {
            cout << *it << "\n";
            s.erase(s.find(*it));
        } else if (it==s.begin())
            cout << "-1\n";
        else {
            it=prev(it);
            cout << *it << "\n";
            s.erase(s.find(*it));
        }
    }
    return 0;
}
