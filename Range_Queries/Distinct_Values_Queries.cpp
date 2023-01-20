/**
 * @brief 離散化 + 離線 + 單點加值 區間求和 線段樹
 *        遍歷每個位置
 *        如果這個數字沒出現過 -> 此位置 + 1
 *        如果這個數字出現過了 -> 此位置 + 1 且 上次出現這個數字的位置 - 1
 *        若要算 [l, r] 的相異元素 -> 就是在遍歷到 r 時，求 [l, r] 的和
 * 
 */

#include <bits/stdc++.h>
#define int long long

using namespace std;

int seg[4*200005];
int arr[200005];
int preidx[200005];

struct item
{
    int num;
    int l, r;
    int ans;
} queries[200005] ;

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
    seg[node]=seg[2*node]+seg[2*node+1];
}

int query(int node, int l, int r, int qL, int qR)
{
    if (qL<=l && r<=qR)
        return seg[node];

    int mid=(l+r)/2;
    if (qR<=mid)
        return query(2*node, l, mid, qL, qR);
    else if (mid+1<=qL)
        return query(2*node+1, mid+1, r, qL, qR);
    else
        return query(2*node, l, mid, qL, qR) + query(2*node+1, mid+1, r, qL, qR);
}

bool cmpr(item a, item b)
{
    return a.r < b.r;
}

bool cmpnum(item a, item b)
{
    return a.num < b.num;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q,i;
    cin >> n >> q;

    vector <int> vec;
    for (i=1;i<=n;i++) {
        cin >> arr[i];
        vec.push_back(arr[i]);
    }
    sort(vec.begin(), vec.end());
    vec.resize( unique(vec.begin(), vec.end()) - vec.begin());
    for (i=1;i<=n;i++)
        arr[i] = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin() + 1;
    
    int a,b;
    for (i=1;i<=q;i++) {
        cin >> a >> b;
        queries[i].num = i;
        queries[i].l = a;
        queries[i].r = b;
    }
    sort(queries+1, queries+q+1, cmpr);

    fill(preidx, preidx+200005, 0);
    int idx=1;
    for (i=1;i<=n;i++) {
        int now = arr[i];
        if (preidx[now] == 0) {
            preidx[now] = i;
            update(1, 1, n, i, 1);
        } else {
            update(1, 1, n, preidx[now], -1);
            preidx[now] = i;
            update(1, 1, n, i, 1);
        }
        while (idx <= q) {
            if (queries[idx].r == i) {
                queries[idx].ans = query(1, 1, n, queries[idx].l, queries[idx].r);
                idx++;
            } else
                break;
        }
        if (idx > q)
            break;
    }
    sort(queries+1, queries+q+1, cmpnum);
    for (i=1;i<=q;i++)
        cout << queries[i].ans << "\n";
    
    return 0;
}