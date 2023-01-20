#include <bits/stdc++.h>
#define int long long

using namespace std;

int seg[4*200005];
int arr[200005];

void build(int node, int l, int r)
{
    if (l==r) {
        seg[node]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    seg[node]=max(seg[2*node], seg[2*node+1]);
}

void update(int node, int l, int r, int idx, int val)
{
    if (l==r) {
        seg[node]+=val;
        return;
    }

    int mid=(l+r)/2;
    if (idx<=mid)
        update(2*node, l, mid, idx, val);
    else
        update(2*node+1, mid+1, r, idx, val);
    seg[node]=max(seg[2*node], seg[2*node+1]);
}

int query(int node, int l, int r, int val)
{
    if (l==r)
        return (seg[node]>=val ? l : 0);

    int mid=(l+r)/2;
    
    if (seg[2*node]>=val)
        return query(2*node, l, mid, val);
    else
        return query(2*node+1, mid+1, r, val);
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

    int x;
    while (q--) {
        cin >> x;
        int tmp=query(1, 1, n, x);
        if (tmp!=0) {
            cout << tmp << " ";
            update(1, 1, n, tmp, -x);
        } else {
            cout << "0 ";
        }
    }
    cout << "\n";
    return 0;
}