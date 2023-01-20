#include <bits/stdc++.h>
#define int long long

using namespace std;
const int MOD=1e9+7;

int dp[100005];

int fastpow(int a, int b)
{
    int res=a, ans=1;
    while (b!=0) {
        if (b&1) ans = (ans*res)%MOD;
        res = (res*res)%MOD;
        b/=2;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(dp, dp+100000, 0);
    int n;
    cin >> n;
    int target=(n*(n+1)/2)/2;
    int i,j;

    dp[0]=1;

    for (i=1;i<=n;i++) {
        for (j=100000;j>=1;j--) {
            if (j-i<0) continue;
            dp[j] = (dp[j]+dp[j-i])%MOD;
        }
    }
    if ((n*(n+1)/2)%2==1) cout << "0\n";
    else  cout << (dp[target]*fastpow(2, MOD-2))%MOD << "\n";
    return 0;
}
