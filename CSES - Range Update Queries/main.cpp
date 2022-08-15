#include <bits/stdc++.h>
#define int long long

using namespace std;

int bit[200005];

void add(int idx, int val)
{
    while (idx<=200000) {
        bit[idx]+=val;
        idx+=(idx&-idx);
    }
    return;
}

int query(int idx)
{
    int ans=0;
    while (idx>=1) {
        ans+=bit[idx];
        idx-=(idx&-idx);
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(bit, bit+200005, 0);
    int n,q,i,a,b,c,d,tmp;
    cin >> n >> q;
    int pre=0;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        add(i, tmp-pre);
        pre=tmp;
    }
    while (q--) {
        cin >> a;
        if (a==1) {
            cin >> b >> c >> d;
            add(b, d);
            add(c+1, -1*d);
        } else {
            cin >> b;
            cout << query(b) << "\n";
        }
    }
    return 0;
}
