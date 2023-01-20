#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mid ((l+r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

int arr[200005];
int seg[4*200005];
int tag[4*200005];
int d[4*200005];

void push(int node, int l, int r)
{
    seg[lc] += (mid-l+1)     * (  tag[node] + (tag[node]+(mid-l)*d[node]) ) / 2ll;
    seg[rc] += (r-(mid+1)+1) * ( (tag[node]+(mid+1-l)*d[node]) + (tag[node]+(r-l)*d[node]) ) / 2ll;
    tag[lc] += tag[node];
    tag[rc] += tag[node] + (mid + 1 - l) * d[node];
    d[lc] += d[node];
    d[rc] += d[node];
    tag[node] = d[node] = 0;
}

void build(int node, int l, int r)
{
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    build(lc, l, mid);
    build(rc, mid+1, r);
    seg[node] = seg[lc] + seg[rc];
}

void update(int node, int l, int r, int ul, int ur, int v)
{
    if (l != r)
        push(node, l, r);
    if (ul <= l && r <= ur) {
        seg[node] += (r-l+1) * (v + (v + (r-l))) / 2;
        tag[node] += v;
        d[node] = 1;
        return;
    }
    if (ur <= mid)
        update(lc, l, mid, ul, ur, v);
    else if (mid+1 <= ul)
        update(rc, mid+1, r, ul, ur, v + max(0ll, mid+1 - max(l, ul)) );
    else
        update(lc, l, mid, ul, ur, v), update(rc, mid+1, r, ul, ur, v + max(0ll, mid+1 - max(l, ul)) );
    seg[node] = seg[lc] + seg[rc];
}

int query(int node, int l, int r, int ql, int qr)
{
    if (l != r)
        push(node, l, r);
    if (ql <= l && r <= qr)
        return seg[node];
    if (qr <= mid)
        return query(lc, l, mid, ql, qr);
    else if (mid+1 <= ql)
        return query(rc, mid+1, r, ql, qr);
    else
        return query(lc, l, mid, ql, qr) + query(rc, mid+1, r, ql, qr);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q, i;
    cin >> n >> q;
    for (i=1;i<=n;i++)
        cin >> arr[i];
    build(1, 1, n);
    
    int a, b, c;
    while (q--) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            update(1, 1, n, b, c, 1);
        } else {
            cin >> b >> c;
            cout << query(1, 1, n, b, c) << "\n";
        }
    }
    
    return 0;
}