/**
5 3
1 2 3 4 5
2 1 4 2
1 2 3 2
3 1 3
 **/
#include <bits/stdc++.h>
#define int long long

using namespace std;

int seg[4*200005];
int ass[4*200005];
int add[4*200005];
int arr[200005];

void build(int node, int L, int R)
{
    if (L==R) {
        seg[node]=arr[L];
        return;
    }
    int mid=(L+R)/2;
    build(2*node, L, mid);
    build(2*node+1, mid+1, R);
    seg[node] = seg[2*node]+seg[2*node+1];
    return;
}

void push(int node, int L, int R)
{
    int mid=(L+R)/2;
    if (ass[node] != 0) {
        seg[2*node] = ass[node]*(mid-L+1);
        ass[2*node] = ass[node];
        seg[2*node+1] = ass[node]*(R-(mid+1)+1);
        ass[2*node+1] = ass[node];
        
        add[2*node] = add[2*node+1] = 0;
        ass[node] = 0;
    }
    if (add[node] != 0) {
        seg[2*node] += add[node]*(mid-L+1);
        add[2*node] += add[node];
        seg[2*node+1] += add[node]*(R-(mid+1)+1);
        add[2*node+1] += add[node];

        add[node] = 0;
    }
}

/// add
void update(int node, int L, int R, int uL, int uR, int val)
{
    if (uL<=L && R<=uR) {
        seg[node] += val*(R-L+1);
        add[node] += val;
        return;
    }

    if (L!=R)
        push(node, L, R);
    
    int mid=(L+R)/2;
    if (uR<=mid)
        update(2*node, L, mid, uL, uR, val);
    else if (mid+1<=uL)
        update(2*node+1, mid+1, R, uL, uR, val);
    else {
        update(2*node, L, mid, uL, uR, val);
        update(2*node+1, mid+1, R, uL, uR, val);
    }
    seg[node] = seg[2*node]+seg[2*node+1];
    return;
}

void assign(int node, int L, int R, int uL, int uR, int val)
{
    if (uL<=L && R<=uR) {
        seg[node] = val*(R-L+1);
        ass[node] = val;
        add[node] = 0;
        return;
    }

    if (L!=R)
        push(node, L, R);
    
    int mid=(L+R)/2;
    if (uR<=mid)
        assign(2*node, L, mid, uL, uR, val);
    else if (mid+1<=uL)
        assign(2*node+1, mid+1, R, uL, uR, val);
    else {
        assign(2*node, L, mid, uL, uR, val);
        assign(2*node+1, mid+1, R, uL, uR, val);
    }
    seg[node] = seg[2*node]+seg[2*node+1];
    return;
}

int query(int node, int L, int R, int qL, int qR)
{
    if (qL<=L && R<=qR)
        return seg[node];
    if (L!=R)
        push(node, L, R);
    
    int mid=(L+R)/2;
    if (qR<=mid)
        return query(2*node, L, mid, qL, qR);
    else if (mid+1<=qL)
        return query(2*node+1, mid+1, R, qL, qR);
    else
        return query(2*node, L, mid, qL, qR) + query(2*node+1, mid+1, R, qL, qR);
/// 因為是將 tag 往下推，故不用 combine，父節點已被算過
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

    fill(ass, ass+4*200005, 0);
    fill(add, add+4*200005, 0);

    while (q--) {
        int p,a,b,x;
        cin >> p;
        if (p==1) {
            cin >> a >> b >> x;
            update(1, 1, n, a, b, x);
        } else if (p==2) {
            cin >> a >> b >> x;
            assign(1, 1, n, a, b, x);
        } else {
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << "\n";
        }
    }
    return 0;
}
