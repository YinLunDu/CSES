#include <bits/stdc++.h>
#define int long long

using namespace std;

struct point {
    int x;
    int y;
    point operator+(point p) { return {x + p.x, y + p.y}; }
    point operator-(point p) { return {x - p.x, y - p.y}; }
    int operator^(point p) { return x * p.y - p.x * y; }
};

signed main()
{
    point a, b, c;
    int q;
    cin >> q;
    while (q--) {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        if (((b - a) ^ (c - a)) > 0) cout << "LEFT\n";
        if (((b - a) ^ (c - a)) < 0) cout << "RIGHT\n";
        if (((b - a) ^ (c - a)) == 0) cout << "TOUCH\n";
    }


    return 0;
}
