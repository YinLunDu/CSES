#include <bits/stdc++.h>
#define ll long long

using namespace std;

///  val  idx
pair <ll, ll> arr[5005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x,tmp;
    cin >> n >> x;
    ll i;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        arr[i]={tmp, i};
    }
    sort(arr+1, arr+n+1);

    for (i=1;i<=n;i++) { /// be controlled

        ll target=x-arr[i].first;

        ll head=1, tail=n;
        while (head<tail) {
            if (head==i) {
                head++;
                continue;
            } else if (tail==i) {
                tail--;
                continue;
            } else {
                if (arr[head].first+arr[tail].first==target) {
                    cout << arr[i].second << " " << arr[head].second << " " << arr[tail].second << "\n";
                    return 0;
                } else if (arr[head].first+arr[tail].first>target)
                    tail--;
                else
                    head++;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
