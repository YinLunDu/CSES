#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[200005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int i;

    for (i=1;i<=n;i++)
        cin >> arr[i];

    set <int> s;

    int L, R=1;
    int mx=0;
    s.clear();
    for (L=1;L<=n;L++) {
        if (s.empty()) s.insert(arr[L]);

        if (L>R) R=L;
        while (true) {
            if (R==n) break;

            if (s.find(arr[R+1])==s.end()) { /// not find
                s.insert(arr[R+1]);
                R++;
            } else
                break;
        }
        mx=max(mx, R-L+1);

        s.erase(s.find(arr[L]));
    }
    cout << mx << "\n";
    return 0;
}
