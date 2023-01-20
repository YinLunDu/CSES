/**
 * @brief 動態開點線段樹
 * 
 */
#include <bits/stdc++.h>

using namespace std;

struct point
{
    int val, lc, rc;
};

vector <point> S;
int arr[200005];

void update(int node, int l, int r, int idx, int x)
{
    if (l == r) {
        S[node].val += x;
        return;
    }
    if (!S[node].lc) {
        S[node].lc = S.size();
        S.push_back({0, 0, 0});
    }
    if (!S[node].rc) {
        S[node].rc = S.size();
        S.push_back({0, 0, 0});
    }
    int mid=(l+r)/2;
    if (idx <= mid)
        update(S[node].lc, l, mid, idx, x);
    else
        update(S[node].rc, mid+1, r, idx, x);
    S[node].val = S[S[node].lc].val + S[S[node].rc].val;
}

int query(int node, int l, int r, int ql, int qr)
{
    if (!node)
        return 0;
    if (ql <= l && r <= qr)
        return S[node].val;
    int mid=(l+r)/2;
    if (qr <= mid)
        return query(S[node].lc, l, mid, ql, qr);
    else if (mid+1 <= ql)
        return query(S[node].rc, mid+1, r, ql, qr);
    else
        return query(S[node].lc, l, mid, ql, qr) + query(S[node].rc, mid+1, r, ql, qr);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    S.push_back({0, 0, 0});
    S.push_back({0, 0, 0}); /// node 編號從 1 開始，須先建好 第 0 跟 1 項
    int n, q, i;
    cin >> n >> q;
    for (i=1;i<=n;i++) {
        cin >> arr[i];
        update(1, 1, 1e9, arr[i], 1);
    }

    char c;
    int a, b;
    while (q--) {
        cin >> c;
        if (c == '!') {
            cin >> a >> b;
            update(1, 1, 1e9, arr[a], -1);
            arr[a] = b;
            update(1, 1, 1e9, arr[a], 1);
        } else {
            cin >> a >> b;
            cout << query(1, 1, 1e9, a, b) << "\n";
        }
    }

    return 0;
}