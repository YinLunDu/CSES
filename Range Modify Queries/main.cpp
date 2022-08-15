/// Segment Tree
/// Lazy Tag
#include <bits/stdc++.h>
#define int long long

using namespace std;

int  seg[4*500005];
int lazy[4*500005];
int  arr[500005];

void build(int node, int L, int R)
{
    if (L==R) {
        seg[node]=arr[L];
        return;
    }
    int mid=(L+R)/2;
    build(2*node, L, mid);
    build(2*node+1, mid+1, R);
    seg[node]=seg[2*node]+seg[2*node+1];
}

void push(int node, int L, int R)
{
    int mid=(L+R)/2;
    seg[2*node]+=lazy[node]*(mid-L+1);
    lazy[2*node]+=lazy[node];

    seg[2*node+1]+=lazy[node]*(R-(mid+1)+1);
    lazy[2*node+1]+=lazy[node];

    lazy[node]=0;
}

void update(int node, int L, int R, int uL, int uR, int val)
{
    if (L!=R) push(node, L, R);

    if (uL<=L && R<=uR) {
        seg[node]+=val*(R-L+1);
        lazy[node]+=val;
        return;
    }
    int mid=(L+R)/2;
    if (uR<=mid)        update(2*node, L, mid, uL, uR, val);
    else if (mid+1<=uL) update(2*node+1, mid+1, R, uL, uR, val);
    else {
        update(2*node, L, mid, uL, uR, val);
        update(2*node+1, mid+1, R, uL, uR, val);
    }

    seg[node]=seg[2*node]+seg[2*node+1];
}

int query(int node, int L, int R, int qL, int qR)
{
    if (L!=R) push(node, L, R);

    if (qL<=L && R<=qR)
        return seg[node];

    int mid=(L+R)/2;
    if (qR<=mid)        return query(2*node, L, mid, qL, qR);
    else if (mid+1<=qL) return query(2*node+1, mid+1, R, qL, qR);
    else return query(2*node, L, mid, qL, qR)+query(2*node+1, mid+1, R, qL, qR);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q,i;
    cin >> n;
    fill(lazy, lazy+4*500005, 0);
    for (i=1;i<=n;i++)
        cin >> arr[i];
    build(1, 1, n);

    cin >> q;
    int a, b, c, x;
    while (q--) {
        cin >> x;
        if (x==1) {
            cin >> a >> b >> c;
            update(1, 1, n, a, b, c);
        } else {
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << "\n";
        }
    }
    return 0;
}
