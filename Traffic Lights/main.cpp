#include <bits/stdc++.h>
#define int long long

using namespace std;

int arr[200005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, n, i;
    cin >> x >> n;
    for (i=1;i<=n;i++)
        cin >> arr[i];

    set <int> s;
    s.insert(0);
    s.insert(x);

    multiset <int> len;
    len.insert(x);

    for (i=1;i<=n;i++) {
        auto it2=s.upper_bound(arr[i]);
        auto it=prev(it2);

        len.erase(len.find(*it2-*it));
        len.insert(*it2-arr[i]);
        len.insert(arr[i]-*it);

        cout << *prev(len.end()) << " ";

        s.insert(arr[i]);
    }

    cout << "\n";
    return 0;
}
