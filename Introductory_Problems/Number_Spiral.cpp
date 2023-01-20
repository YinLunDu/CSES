#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q,x,y;
    cin >> q;

    while (q--) {
        cin >> x >> y;
        if (x==y)
            cout << x*x-(x-1) << "\n";
        else if (x>y) {
            if (x%2==1) {
                cout << (x-1)*(x-1)+y << "\n";
            } else {
                cout << (x-1)*(x-1)+x+x-y << "\n";
            }
        } else {
            if (y%2==0) {
                cout << (y-1)*(y-1)+x << "\n";
            } else {
                cout << (y-1)*(y-1)+y+y-x << "\n";
            }
        }
    }
    return 0;
}
