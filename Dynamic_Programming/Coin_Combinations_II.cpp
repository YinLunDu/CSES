#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD=1e9+7;

ll dp[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll i, j, n, x, v;
    cin >> n >> x;
    fill(dp, dp+1000005, 0);

    dp[0]=1;
    for (i=1;i<=n;i++) {
        cin >> v;
        for (j=1;j<=x;j++) {
            if (j-v>=0)
                dp[j] = (dp[j]+dp[j-v]) % MOD;
        }
    }
    cout << dp[x] << "\n";
    return 0;
}
