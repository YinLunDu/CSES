#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll arr[200002];
ll pre[200002];
ll last[200002];

ll DC(ll L, ll R)
{
    if (L==R) return arr[L];
    ll mid=(L+R)/2;
    ll a=DC(L, mid);
    ll b=DC(mid+1, R);
    ll c=(a>b ? a : b);
    ll sum1=-1e9, sum2=-1e9;
    ll now,i;

    for (i=mid;i>=L;i--) {
        now=last[i]-last[mid+1];
        if (now>sum1) sum1=now;
    }
    for (i=mid+1;i<=R;i++) {
        now=pre[i]-pre[mid];
        if (now>sum2) sum2=now;
    }

    return max(c, sum1+sum2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,i;
    cin >> n;
    for (i=0;i<n;i++)
        cin >> arr[i];
    pre[0]=arr[0];
    for (i=1;i<n;i++)
        pre[i]=pre[i-1]+arr[i];
    last[n]=arr[n];
    for (i=n-1;i>=0;i--)
        last[i]=last[i+1]+arr[i];

    cout << DC(0, n-1) << "\n";
    return 0;
}
