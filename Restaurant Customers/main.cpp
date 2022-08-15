#include <bits/stdc++.h>
#define int long long

using namespace std;

vector <pair <int, int>> vec;
priority_queue <int, vector <int>, greater <int>> pq;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,i;
    cin >> n;
    int a,b;
    for (i=1;i<=n;i++) {
        cin >> a >> b;
        vec.push_back({a,b});
    }
    sort(vec.begin(), vec.end());

    int mx=0;
    for (i=0;i<n;i++) {
        pair <int, int> tmp=vec[i];
        pq.push(tmp.second);
        while (!pq.empty()) {
            if (pq.top()>=tmp.first)
                break;
            else
                pq.pop();
        }
        int sz=pq.size();
        mx=max(mx, sz);
    }
    cout << mx << "\n";
    return 0;
}
