#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool is_prime[1000005];
vector <ll> prime;
ll lpf[1000005];

void init()
{
    fill(is_prime, is_prime+1000005, true);
    ll i;
    for (i=2;i<=1000000;i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            lpf[i]=i;
        }
        for (auto p:prime) {
            if (p*i>=1000001) break;
            is_prime[p*i]=false;
            lpf[p*i]=p;
            if (i%p==0) break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q,n;

    init();

    cin >> q;
    while (q--) {
        cin >> n;
        ll ans=1;

        while (n!=1) {
            ll cnt=0;
            ll tmp=lpf[n];
            while (n%tmp==0) {
                n/=tmp;
                cnt++;
            }
            ans*=cnt+1;
        }
        cout << ans << "\n";
    }

    return 0;
}
