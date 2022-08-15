#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD=1e9+7;

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
    int n;
    cin >> n;
    cout << fastpow(2, n) << "\n";
    return 0;
}
