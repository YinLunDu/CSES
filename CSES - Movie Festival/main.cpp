#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool cmp(pair <ll,ll> p1, pair <ll,ll> p2)
{
    return p1.second<p2.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector < pair <ll,ll> > m;
    ll a, b, i;
    for (i=0;i<n;i++) {
        cin >> a >> b;
        m.push_back({a,b});
    }
    sort(m.begin(), m.end(), cmp);
    ll tmp=-1;
    ll ans=0;
    for (i=0;i<n;i++) {
        if (m[i].first>=tmp) {
            ans++;
            tmp=m[i].second;
        }
    }
    cout << ans << "\n";
    return 0;
}
