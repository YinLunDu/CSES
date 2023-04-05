#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector<int> G[200005];
int arr[200005];
int euler_tour[400005];
pii range[400005];
int bit[400005];
int idx = 0;

int qry(int idx) {
    int ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & -idx);
    }
    return ans;
}

int query(int l, int r) {
    return qry(r) - qry(l-1);
}

void update(int idx, int val) {
    while (idx <= 400000) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
    return;
}

void euler(int v, int p)
{
    euler_tour[++idx] = v;
    for (int u:G[v]) {
        if (u == p) continue;
        euler(u, v);
    }
    euler_tour[++idx] = v;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q, i, a, b, c;
    cin >> n >> q;
    for (i=1; i<=n; i++)
        cin >> arr[i];
    for (i=1; i<=n-1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    euler(1, -1);
    for (i=1; i<=idx; i++) {
        update(i, arr[euler_tour[i]]);
        if (range[euler_tour[i]].first)
            range[euler_tour[i]].second = i;
        else
            range[euler_tour[i]].first = i;
    }

    while (q--) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            update(range[b].first, c - arr[b]);
            update(range[b].second, c - arr[b]);
            arr[b] = c;
        } else {
            cin >> b;
            cout << query(range[b].first, range[b].second) / 2 << "\n";
        }
    }

    return 0;
}