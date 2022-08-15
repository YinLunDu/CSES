#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x;
    ll i,j;
    ///  price    page
    ll h[1005], s[1005];
    cin >> n >> x;
    for (i=1;i<=n;i++) cin >> h[i];
    for (i=1;i<=n;i++) cin >> s[i];

    fill(dp, dp+100005, -1);
    dp[0]=0;
    for (i=1;i<=n;i++) {
        for (j=x;j>=1;j--) {
            if (j-h[i]>=0)
                dp[j]=max(dp[j], dp[j-h[i]]+s[i]);
        }
    }
    ll ans=0;
    for (i=1;i<=x;i++)
        ans=max(ans, dp[i]);
    cout << ans << "\n";
    return 0;
}
