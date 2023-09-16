#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int x, n, tmp;
    priority_queue <int, vector <int>, greater<int>> pq;
    cin >> x >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        pq.push(tmp);
    }
    
    int ans = 0;
    while (pq.size() >= 2) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    cout << ans << "\n";
    return 0;
}