#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll bit[200005];
ll arr[200005];

void add(ll idx, ll val)
{
    while (idx<=2e5) {
        bit[idx]+=val;
        idx+=idx&(-idx);
    }
    return;
}

ll query(ll idx) /// [1,idx] SUM
{
    if (idx==0) return 0;
    ll total=0;
    while (idx>0) {
        total+=bit[idx];
        idx-=idx&(-idx);
    }
    return total;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll i;
    ll n,q,tmp,a,b,c;
    cin >> n >> q;
    fill(bit, bit+200005, 0);
    for (i=1;i<=n;i++) {
        cin >> tmp;
        add(i, tmp);
        arr[i]=tmp;
    }
    while (q--) {
        cin >> a >> b >> c;
        if (a==1) {
            add(b, c-arr[b]);
            arr[b]=c;
        } else {
            ll ans=query(c)-query(b-1);
            cout << ans << "\n";
            //cout << query(c) << " " << query(b-1) << "\n";
        }
    }
    return 0;
}
