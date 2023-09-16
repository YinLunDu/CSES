#include <bits/stdc++.h>
#define int long long
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

vector <int> G[100005];
int in[100005];
bool vis[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    loop(i, 1, m) {
        cin >> a >> b;
        G[a].push_back(b);
        in[b]++;
    }

    queue <int> q;
    loop(i, 1, n) {
        if (in[i] == 0)
            q.push(i);
    }

    vector <int> ans;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        ans.push_back(v);
        for (auto u : G[v]) {
            in[u]--;
            if (in[u] == 0)
                q.push(u);
        }
    }

    if ((int)ans.size() == n) {
        for (int it : ans)
            cout << it << " ";
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
