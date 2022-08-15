#include <bits/stdc++.h>
#define int long long
#define pii pair <int, int>

using namespace std;


signed main()
{
    priority_queue < pii, vector <pii>, greater <pii> > pq;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector <int> v;
    int tmp;
    int i;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for (i=0;i<n;i++)
        pq.push({0, i});

    pii p=pq.top();
    cout << p.second << "\n";

    for (i=1;i<=t;i++) {
        pii p=pq.top();
        pq.pop();
        pq.push({p.first+v[p.second], p.second});
    }

    int mx=0;
    while (!pq.empty()) {
        pii p=pq.top();
        mx=max(mx, p.first);
        pq.pop();
    }

    cout << mx << "\n";
    return 0;
}
