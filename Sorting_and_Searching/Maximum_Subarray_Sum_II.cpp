#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int pre[200005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, i, tmp;
    cin >> n >> a >> b;

    pre[0] = 0;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        pre[i] = pre[i-1] + tmp;
    }
    
    // i-b ~ i-a
    deque <int> dq;
    dq.push_back(0);
    int ans = -1e18;
    for (i=1;i<=n;i++){
        while (!dq.empty() && dq.front() < i-b)
            dq.pop_front();
        if (i-a >= 1) {
            while (!dq.empty() && pre[dq.back()] >= pre[i-a])
                dq.pop_back();
            dq.push_back(i-a);
        }
        if (i-b <= dq.front() && dq.front() <= i-a)
            ans = max(ans, pre[i] - pre[dq.front()]);
        //cout << pre[i] - pre[dq.front()] << "\n";
    }
    cout << ans << "\n";
    
    return 0;
}