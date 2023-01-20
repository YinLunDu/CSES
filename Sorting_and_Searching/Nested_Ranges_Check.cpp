#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

struct item
{
    int num, l, r;
};

vector <item> v;
int bit[400005];
int ans[400005][2];

void update(int idx, int val)
{
    while (idx <= 400000) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int query(int idx)
{
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

bool cmpl(item a, item b)
{
    if (a.l == b.l)
        return a.r > b.r;
    else
        return a.l < b.l;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,i,j,a,b;
    cin >> n;

    vector <int> arr;
    for (i=1;i<=n;i++) {
        cin >> a >> b;
        v.push_back({i, a, b});

        arr.push_back(a);
        arr.push_back(b);
    }
    sort(arr.begin(), arr.end());
    arr.resize( unique(arr.begin(), arr.end()) - arr.begin() );

    for (i=0;i<=n-1;i++) {
        v[i].l = lower_bound(arr.begin(), arr.end(), v[i].l) - arr.begin() + 1;
        v[i].r = lower_bound(arr.begin(), arr.end(), v[i].r) - arr.begin() + 1;
    }

    sort(v.begin(), v.end(), cmpl);


    fill(bit, bit+400005, 0);
    for (i=n-1;i>=0;i--) {
        ans[v[i].num][0] = query(v[i].r);
        update(v[i].r, 1);
    }

    fill(bit, bit+400005, 0);
    for (i=0;i<=n-1;i++) {
        ans[v[i].num][1] = query(400000) - query(v[i].r - 1);
        update(v[i].r, 1);
    }

    for (j=1;j<=n;j++)
        cout << (ans[j][0] ? 1 : 0) << " ";
    cout << "\n";
    for (j=1;j<=n;j++)
        cout << (ans[j][1] ? 1 : 0) << " ";
    cout << "\n";

    return 0;
}