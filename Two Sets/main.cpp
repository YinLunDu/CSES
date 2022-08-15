#include <bits/stdc++.h>
#define int long long

using namespace std;

bool out[1000005];

signed main()
{
    int n;
    cin >> n;
    if ((n*(n+1)/2)%2==1) {
        cout << "NO\n";
        return 0;
    } else
        cout << "YES\n";
    int i;
    int target=n*(n+1)/4;
    int sum=0;

    int cnt=0;
    fill(out, out+n+1, false);

    for (i=n;i>=1;i--) {
        if (sum+i<=target) {
            sum+=i;
            out[i]=1;
            cnt++;
        }
        if (sum==target)
            break;
    }

    cout << cnt << "\n";
    for (i=1;i<=n;i++)
        if (out[i])
            cout << i << " ";
    cout << "\n";
    cout << n-cnt << "\n";
    for (i=1;i<=n;i++)
        if (!out[i])
            cout << i << " ";

    return 0;
}
