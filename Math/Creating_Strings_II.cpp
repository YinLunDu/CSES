#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MOD=1e9+7;

ll down[1000001];
ll up[1000001];

ll fastpow(ll a, ll b)
{
    ll ans=1, res=a;
    while (b!=0) {
        if (b&1) ans = (ans*res)%MOD;
        b/=2;
        res = (res*res)%MOD;
    }
    return ans;
}

/// x^-1 = x^m-2 (mod m)

ll f(ll n) /// Fermat's Little Theorem
{
    return fastpow(n, MOD-2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll i;

    down[1]=1;
    for (i=2;i<=1000000;i++) {
        down[i] = (down[i-1]*f(i))%MOD;
    }

    up[1]=1;
    for (i=2;i<=1000000;i++) {
        up[i] = (up[i-1]*i)%MOD;
    }

    ll letter[100];
    fill(letter, letter+30, 0);
    string str;
    getline(cin, str);
    for (auto it:str)
        letter[it-'a']++;

    ll sz=str.size();

    ll ans=up[sz];
    for (i=0;i<26;i++) {
        if (letter[i]>0)
            ans = (ans*down[letter[i]])%MOD;
    }

    cout << ans << "\n";
    return 0;
}
