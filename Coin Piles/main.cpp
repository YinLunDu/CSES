#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,a,b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a==0 && b==0)
            cout << "YES\n";
        else if (a==0 || b==0)
            cout << "NO\n";
        else {
            int x=(2*a-b)/3, y=(2*b-a)/3;
            if (x<0 || y<0)
                cout << "NO\n";
            else if ((2*x+y==a) && (2*y+x==b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
