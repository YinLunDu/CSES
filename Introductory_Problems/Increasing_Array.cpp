#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll arr[200005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,i;
    cin >> n;
    for (i=1;i<=n;i++)
        cin >> arr[i];
    ll ans=0;
    for (i=2;i<=n;i++) {
        if (arr[i]<arr[i-1]) {
            ans+=arr[i-1]-arr[i];
            arr[i]=arr[i-1];
        }
    }
    cout << ans << "\n";
    return 0;
}
