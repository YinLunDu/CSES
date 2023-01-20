#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x, n, i, tmp;
    priority_queue <ll, vector <ll>, greater<ll>> pq;
    cin >> x >> n;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        pq.push(tmp);
    }
    ll ans=0;
    while (pq.size()>=2) {
        ll a=pq.top();
        pq.pop();
        ll b=pq.top();
        pq.pop();
        ans+=a+b;
        pq.push(a+b);
    }
    cout << ans << "\n";
}
