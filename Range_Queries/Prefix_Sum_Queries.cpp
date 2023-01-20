#include <bits/stdc++.h>
#define int long long

using namespace std;

int arr[200005];

struct point
{
    int pre, sum;
} seg[4*200005] ;

point combine(point lnode, point rnode) {
    point p;
    p.pre = max(lnode.pre, lnode.sum + rnode.pre);
    p.sum = lnode.sum + rnode.sum;
    return p;
}

void build(int node, int l, int r)
{
    if (l == r) {
        seg[node].pre = (arr[l] > 0 ? arr[l] : 0);
        seg[node].sum = arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    seg[node] = combine(seg[2*node], seg[2*node+1]);
}

void update(int node, int l, int r, int idx, int val)
{
    if (l == r) {
        seg[node].pre = (val > 0 ? val : 0);
        seg[node].sum = val;
        return;
    }

    int mid=(l+r)/2;
    if (idx <= mid)
        update(2*node, l, mid, idx, val);
    else
        update(2*node+1, mid+1, r, idx, val);
    seg[node] = combine(seg[2*node], seg[2*node+1]);
}

point query(int node, int l, int r, int qL, int qR)
{
    if (qL <= l && r <= qR)
        return seg[node];
    
    int mid=(l+r)/2;
    if (qR <= mid)
        return query(2*node, l, mid, qL, qR);
    else if (mid+1 <= qL)
        return query(2*node+1, mid+1, r, qL, qR);
    else {
        return combine(query(2*node, l, mid, qL, qR), query(2*node+1, mid+1, r, qL, qR));
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q,i;
    cin >> n >> q;
    

    for (i=1;i<=n;i++)
        cin >> arr[i];
    
    build(1, 1, n);

    int v;
    int x,k;
    int l,r;
    while (q--) {
        cin >> v;
        if (v==1) {
            cin >> x >> k;
            update(1, 1, n, x, k);
        } else {
            cin >> l >> r;
            point ans = query(1, 1, n, l, r);
            cout << ans.pre << "\n";
        }
    }
    
    return 0;
}