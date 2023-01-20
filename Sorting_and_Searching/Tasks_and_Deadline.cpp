#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <pair <ll, ll>> vec;

bool cmp(pair <ll, ll> p1, pair <ll, ll> p2)
{
    return p1.first<p2.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,a,b,i;
    cin >> n;
    for (i=1;i<=n;i++) {
        cin >> a >> b;
        vec.push_back({a,b});
    }
    sort(vec.begin(), vec.end(), cmp);

    ll now=0, ans=0;
    for (i=0;i<n;i++) {
        now+=vec[i].first;
        ans+=vec[i].second-now;
    }
    cout << ans << "\n";
    return 0;
}
