#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int Lseg[4*200005], Rseg[4*200005], arr[200005];

void Lupdate(int node, int l, int r, int idx, int val)
{
    if (l == r) {
        Lseg[node] += val;
        return;
    }
    int mid = (l+r)/2;
    if (idx <= mid)
        Lupdate(2*node, l, mid, idx, val);
    else
        Lupdate(2*node+1, mid+1, r, idx, val);
    Lseg[node] = min(Lseg[2*node], Lseg[2*node+1]);
}

void Rupdate(int node, int l, int r, int idx, int val)
{
    if (l == r) {
        Rseg[node] += val;
        return;
    }
    int mid = (l+r)/2;
    if (idx <= mid)
        Rupdate(2*node, l, mid, idx, val);
    else
        Rupdate(2*node+1, mid+1, r, idx, val);
    Rseg[node] = min(Rseg[2*node], Rseg[2*node+1]);
}

int Lquery(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return Lseg[node];
    
    int mid = (l+r)/2;
    if (qr <= mid)
        return Lquery(2*node, l, mid, ql, qr);
    else if (mid+1 <= ql)
        return Lquery(2*node+1, mid+1, r, ql, qr);
    else
        return min( Lquery(2*node, l, mid, ql, qr), Lquery(2*node+1, mid+1, r, ql, qr) );
}

int Rquery(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return Rseg[node];
    
    int mid = (l+r)/2;
    if (qr <= mid)
        return Rquery(2*node, l, mid, ql, qr);
    else if (mid+1 <= ql)
        return Rquery(2*node+1, mid+1, r, ql, qr);
    else
        return min( Rquery(2*node, l, mid, ql, qr), Rquery(2*node+1, mid+1, r, ql, qr) );
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q, i;
    cin >> n >> q;
    for (i=1;i<=n;i++)
        cin >> arr[i];
    for (i=1;i<=n;i++)
        Lupdate(1, 1, n, i, arr[i] + i);
    for (i=n;i>=1;i--)
        Rupdate(1, 1, n, i, arr[i] + (n-i+1));

    int v, a, b, idx;
    while (q--) {
        cin >> v;
        if (v == 1) {
            cin >> a >> b;
            Lupdate(1, 1, n, a, b-arr[a]);
            Rupdate(1, 1, n, a, b-arr[a]);
            arr[a] = b;
        } else {
            cin >> idx;
            int ans = 1e18;
            ans = min(ans, Lquery(1, 1, n, idx, n) - idx);
            ans = min(ans, Rquery(1, 1, n, 1, idx) - (n - idx + 1));
            cout << ans << "\n";
        }
    }
    
    return 0;
}