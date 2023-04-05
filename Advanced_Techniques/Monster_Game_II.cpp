#include <bits/stdc++.h>
#define int long long
#define mid (l+r)/2

using namespace std;

const int mxN = 1e6;
const int INF = 1e18;
int s[200005], f[200005];
int dp[200005];

struct line
{
    int m, k;
    int lc, rc;
    int operator()(int x){
        return m * x + k;
    }
};

vector <line> seg;

void update(int node, int l, int r, line add)
{
    if (l == r) {
        if (add(l) > seg[node](l)) {
            swap(add.m, seg[node].m);
            swap(add.k, seg[node].k);
        }
        return;
    }
/// 預設 seg[node] 的斜率 < add 的斜率
    if (seg[node].m > add.m) {
        swap(add.m, seg[node].m);
        swap(add.k, seg[node].k);
    }
/// 動態開點
    if (!seg[node].lc){
        seg[node].lc = seg.size();
        seg.push_back({0, -INF, 0, 0});
    }
    if (!seg[node].rc){
        seg[node].rc = seg.size();
        seg.push_back({0, -INF, 0, 0});
    }

    if (seg[node](mid) < add(mid)) {
        swap(add.m, seg[node].m);
        swap(add.k, seg[node].k);
        update(seg[node].lc, l, mid, add);
    } else {
        update(seg[node].rc, mid+1, r, add);
    }
}

int query(int node, int l, int r, int x)
{
    if (!seg[node].m && !seg[node].k) return 0;
    if (l == r)
        return seg[node](x);
    if (x <= mid)
        return max(seg[node](x), query(seg[node].lc, l, mid, x));
    else
        return max(seg[node](x), query(seg[node].rc, mid+1, r, x));
}

signed main()
{
    seg.push_back({0, -INF, 0, 0});
    seg.push_back({0, -INF, 0, 0});
    seg.push_back({0, -INF, 0, 0});

    int n, x, i;
    cin >> n >> x;
    
    for (i=1;i<=n;i++)  
        cin >> s[i];
    for (i=1;i<=n;i++)  
        cin >> f[i];
    
    update(1, 1, mxN, {-x, 0, 0, 0});
    for (i=1;i<=n;i++) {
        dp[i] = query(1, 1, mxN, s[i]);
        update(1, 1, mxN, {-f[i], dp[i], 0, 0});
    }
    cout << -dp[n] << "\n";

    return 0;
}