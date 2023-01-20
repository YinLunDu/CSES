#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>

using namespace std;

priority_queue <pii, vector<pii>, less<pii> > pq;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i;
    int n, arr[200005];
    cin >> n;

    for (i=1;i<=n;i++)
        cin >> arr[i];
    
    for (i=1;i<=n;i++) {
        pii now={arr[i], i};

        int ans=0;
        while (true) {
            if (pq.size()==0)
                break;
            pii tmp=pq.top();
            if (now.first>tmp.first) {
                ans=tmp.second;
                break;
            } else {
                pq.pop();
            }
        }
        pq.push(now);
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}

