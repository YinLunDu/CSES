#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

/// 二進位寫法
long long fastpow(long long a, long long b)
{
    long long ans=1, now=a;
    while (b!=0) {
        if (b&1)
            ans = ans*now%MOD;
        now = now*now%MOD;
        b/=2;
    }
    return ans;
}
/// recursive method
/*
long long fastpow(long long a, long long b)
{
    if (b==0) return 1;
    if (b==1) return a%MOD;

    long long half=fastpow(a,b/2);

    if (b%2) return half%MOD * half%MOD * a%MOD;
    else     return half%MOD * half%MOD;
}
*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long a,b;
    cin >> n;
    long long ans;
    while (n--) {
        cin >> a >> b;
        ans=fastpow(a,b);
        cout << ans%MOD << "\n";
    }
    return 0;
}
