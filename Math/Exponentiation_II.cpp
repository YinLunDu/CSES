#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll fastpow(ll a, ll b, ll mod)
{
    if (a==0 && b==0) return 1;
    ll ans=1, now=a;
    while (b!=0) {
        if (b&1)
            ans=(ans*now)%mod;
        now=(now*now)%mod;
        b/=2;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Q;
    cin >> Q;
    ll a,b,c; ll tmp,ans;
    while (Q--) {
        cin >> a >> b >> c;
        tmp=fastpow(b, c, 1000000006);
        ans=fastpow(a,tmp,1000000007);
        cout << ans << "\n";
    }
    return 0;
}
