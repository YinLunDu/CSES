#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector < pair<ll, ll> > item;
ll dp[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x,i;
    cin >> n >> x;

/// price page copy
    ll h[105], s[105], k[105];

    for (i=1;i<=n;i++) cin >> h[i];
    for (i=1;i<=n;i++) cin >> s[i];
    for (i=1;i<=n;i++) cin >> k[i];

    for (i=1;i<=n;i++) {
        ll tmp=1;
        ll hh=h[i], ss=s[i], kk=k[i];
        while (kk>tmp) {
            item.push_back( {tmp*hh, tmp*ss} );
            kk-=tmp;
            tmp*=2;
        }
        if (kk!=0) item.push_back( {kk*hh, kk*ss} );
    }

    fill(dp, dp+100005, -1);
    dp[0]=0; ll j;
    for (auto it:item) {
        for (j=x;j>=1;j--) {
            if (j-it.first>=0) {
                dp[j]=max(dp[j], dp[j-it.first]+it.second);
            }
        }
    }

    ll big=0;
    for (i=1;i<=x;i++)
        big=max(big, dp[i]);
    cout << big << "\n";
/*
    for (auto it:item)
        cout << it.first << " " << it.second << "\n";
*/
    return 0;
}
