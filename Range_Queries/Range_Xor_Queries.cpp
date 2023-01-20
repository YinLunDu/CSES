#include <bits/stdc++.h>
#define int long long

using namespace std;

int seg[4*200005];
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
    seg[node]=seg[2*node]^seg[2*node+1];
}

int query(int node, int L, int R, int qL, int qR)
{
    if (qL<=L && R<=qR)
        return seg[node];

    int mid=(L+R)/2;
    if (qR<=mid)
        return query(2*node, L, mid, qL, qR);
    else if (mid+1<=qL)
        return query(2*node+1, mid+1, R, qL, qR);
    else
        return query(2*node, L, mid, qL, qR)^query(2*node+1, mid+1, R, qL, qR);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, i, a, b;
    cin >> n >> q;
    for (i=1;i<=n;i++)
        cin >> arr[i];
    build(1, 1, n);
    while (q--) {
        cin >> a >> b;
        cout << query(1, 1, n, a, b) << "\n";
    }
    return 0;
}
