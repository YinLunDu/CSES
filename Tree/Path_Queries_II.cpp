/*
1. depth[i] : 節點 i 的深度
2. father[i] : 節點 i 的父節點
3. sz[i] : 節點 i 的子樹大小
4. mxson[i] : 節點 i 的重兒子編號
5. topf[i] : 節點 i 所在的重鏈深度最低的節點的編號
6. id[i] : 節點 i 的 DFS 序

dfs1 求出 father depth sz mxson
dfs2 求出 topf id
*/
#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)

using namespace std;

int seg[4*200005];
int arr[200005];
int input[200005];
int n;

vector <int> G[200005];
int father[200005], sz[200005], depth[200005], mxson[200005];
int topf[200005], id[200005], id_cnt = 0;

void build(int node, int l, int r)
{
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    seg[node] = max(seg[lc], seg[rc]);
}

void update(int node, int l, int r, int idx, int val)
{
    if (l == r) {
        seg[node] = val;
        return;
    }
    if (idx <= mid)
        update(lc, l, mid, idx, val);
    else
        update(rc, mid + 1, r, idx, val);
    seg[node] = max(seg[lc], seg[rc]);
}

int query(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return seg[node];

    if (qr <= mid)
        return query(lc, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        return query(rc, mid + 1, r, ql, qr);
    else
        return max(query(lc, l, mid, ql, qr), query(rc, mid + 1, r, ql, qr));
}

void dfs(int v, int p)
{
    father[v] = p;
    sz[v] = 1;
    depth[v] = (p == -1 ? 1 : depth[p] + 1);
    mxson[v] = 0;
    for (int u:G[v]) {
        if (u == p) continue;
        dfs(u, v);
        sz[v] += sz[u];
        if (sz[u] > sz[mxson[v]])
            mxson[v] = u;
    }
}

void dfs2(int v, int top)
{
    id[v] = ++id_cnt;
    topf[v] = top;

    if (mxson[v]) dfs2(mxson[v], top);

    for (int u:G[v]) {
        if (u == father[v] || u == mxson[v]) continue;
        dfs2(u, u);
    }
}

int qry(int a, int b)
{
    int res = 0;
    while (topf[a] != topf[b]) {
        if (depth[topf[a]] < depth[topf[b]]) swap(a, b);
        res = max(res, query(1, 1, n, id[topf[a]], id[a]));
        a = father[topf[a]];
    }

    if (depth[a] < depth[b]) swap(a, b);
    res = max(res, query(1, 1, n, id[b], id[a]));

    return res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> n >> q;
    for (int i=1; i<=n; i++)
        cin >> input[i];
    
    int a, b;
    for (int i=1; i<=n-1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, -1);
    dfs2(1, 1);

    for (int i=1; i<=n; i++)
        arr[id[i]] = input[i];
    build(1, 1, n);

    int op;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            update(1, 1, n, id[a], b);
        } else {
            cin >> a >> b;
            cout << qry(a, b) << " ";
        }
    }
    cout << "\n";

    return 0;
}