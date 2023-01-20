/// »¼°jªTÁ|
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> vec;
vector <ll> a;
ll mid;
ll ans;
ll n,x;

void dfs1(int sum, int idx)
{
    if (idx>mid) {
        a.push_back(sum);
        return;
    }

    dfs1(sum, idx+1);
    dfs1(sum+vec[idx], idx+1);
}

void dfs2(int sum, int idx)
{
    if (sum>x) return;

    if (idx>n-1) {
        ans+=upper_bound(a.begin(), a.end(), x-sum)-lower_bound(a.begin(), a.end(), x-sum);
        return;
    }

    dfs2(sum, idx+1);
    dfs2(sum+vec[idx], idx+1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll i;
    ll tmp;

    cin >> n >> x;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }

    mid=(0+n)/2-1;

    dfs1(0, 0);
    sort(a.begin(), a.end());

    ans=0;
    dfs2(0, mid+1);

    cout << ans << "\n";
    return 0;
}

/// TLE
/*
#include <bits/stdc++.h>
#define ll long long

using namespace std;

map <ll, ll> mp1, mp2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x,i;
    vector <ll> vec;
    ll tmp;
    cin >> n >> x;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    ll mid=(0+n)/2-1;

    ll sum; ll idx;

    /// total_amount : mid+1 ----> 2^(mid+1)-1

    for (ll i=0 ; i< 1 << (mid+1) ; i++) {

        ll now=i; sum=0; idx=0;
        while (now!=0) {
            if (now&1)
                sum+=vec[idx];
            now/=2;
            idx++;
        }
        mp1[sum]++;
    }

    /// total_amount : n-mid-1 ----> 2^(n-mid-1)-1

    for (ll i=0 ; i< 1 << (n-mid-1) ; i++) {
        ll now=i; sum=0; idx=mid+1;
        while (now!=0) {
            if (now&1)
                sum+=vec[idx];
            now/=2;
            idx++;
        }
        mp2[sum]++;
    }

    ll ans=0;
    for (auto it=mp1.begin();it!=mp1.end();it++) {
        ll a=it->first, a_amount=it->second;
        if (mp2.find(x-a)!=mp2.end())
            ans+=a_amount*(mp2[x-a]);
    }
    cout << ans << "\n";
    return 0;
}
*/
