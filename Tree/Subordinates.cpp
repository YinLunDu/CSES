#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> G[200005];
vector<int> topo;
int cnt[200005];
int in[200005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, i, x;
    cin >> n;
    for (i=2;i<=n;i++) {
        cin >> x;
        G[i].push_back(x);
        in[x]++;
    }

    queue<int> q;
    for (i=1;i<=n;i++)
        if (!in[i]) {
            q.push(i);
            cnt[i] = 0;
        }
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        topo.push_back(now);
        for (auto it:G[now]) {
            in[it]--;
            if (!in[it])
                q.push(it);
        }
    }

    for (auto now:topo) {
        for (auto it:G[now]) {
            cnt[it] += cnt[now] + 1;
        }
    }


    for (i=1;i<=n;i++)
        cout << cnt[i] << " ";
    cout << "\n";
    return 0;
}
