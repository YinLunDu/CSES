#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9+7;

int fastpow(int a, int b)
{
    int res = a, ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * res) % mod;
        res = (res * res) % mod;
        b /= 2;
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
