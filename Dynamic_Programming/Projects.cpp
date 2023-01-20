/**
 dp[r]=max(dp[1],dp[2],...,dp[l-1])+w[i]
 **/
#include <bits/stdc++.h>
#define int long long

using namespace std;

struct item
{
    int l,r,w;
} arr[200005];

vector <int> v;
int bit[400005];

bool cmp(item x, item y)
{
    return x.l<y.l;
}

int query(int idx)
{
    int mx=0;
    while (idx!=0) {
        mx=max(mx, bit[idx]);
        idx-=(idx&-idx);
    }
    return mx;
}

void update(int idx, int val)
{
    while (idx<=400000) {
        bit[idx]=max(bit[idx], val);
        idx+=(idx&-idx);
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,i;
    cin >> n;
    for (i=1;i<=n;i++) {
        cin >> arr[i].l >> arr[i].r >> arr[i].w;
        v.push_back(arr[i].l);
        v.push_back(arr[i].r);
    }
    sort(v.begin(), v.end());
    v.resize( unique(v.begin(), v.end())-v.begin() );

    for (i=1;i<=n;i++) {
        arr[i].l=lower_bound(v.begin(), v.end(), arr[i].l)-v.begin()+1;
        arr[i].r=lower_bound(v.begin(), v.end(), arr[i].r)-v.begin()+1;
    }

    sort(arr+1, arr+n+1, cmp);

/// dp[r]=max(dp[1],dp[2],...,dp[l-1])+w[i]

    fill(bit, bit+400005, 0);
    for (i=1;i<=n;i++) {
        int x=query(arr[i].l-1)+arr[i].w;
        update(arr[i].r, x);
    }
    cout << query(400000) << "\n";
    return 0;
}
