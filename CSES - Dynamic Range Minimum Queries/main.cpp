#include <bits/stdc++.h>
#define int long long

using namespace std;

int seg[4*200005], arr[200005];

void build(int node, int l, int r)
{
    if (l==r) {
        seg[node]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    seg[node]=min(seg[2*node], seg[2*node+1]);
    return;
}

void update(int idx, int val, int node, int l, int r)
{
    if (l==r) {
        seg[node]=val;
        return;
    }
    int mid=(l+r)/2;
    if (idx<=mid)
        update(idx, val, 2*node, l, mid);
    else
        update(idx, val, 2*node+1, mid+1, r);
    seg[node]=min(seg[2*node], seg[2*node+1]);
}

int query(int ql, int qr, int node, int l, int r)
{
    if (ql<=l && r<=qr)
        return seg[node];
    int mid=(l+r)/2;

    if (qr<=mid)
        return query(ql, qr, 2*node, l, mid);
    else if (mid<ql)
        return query(ql, qr, 2*node+1, mid+1, r);
    else {
        int a=query(ql, qr, 2*node, l, mid);
        int b=query(ql, qr, 2*node+1, mid+1, r);
        return min(a,b);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q, i, a, b, c;
    cin >> n >> q;
    for (i=1;i<=n;i++)
        cin >> arr[i];
    build(1, 1, n);
    while (q--) {
        cin >> a >> b >> c;
        if (a==1) {
            update(b, c, 1, 1, n);
        } else {
            cout << query(b, c, 1, 1, n) << "\n";
        }
    }
    return 0;
}
