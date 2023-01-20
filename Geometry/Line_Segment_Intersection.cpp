#include <bits/stdc++.h>
#define int long long

using namespace std;

struct point
{
    int x; int y;
    point operator + (point p) { return {x+p.x, y+p.y}; }
    point operator - (point p) { return {x-p.x, y-p.y}; }
    int operator * (point p) { return x*p.x+y*p.y; }
    int operator ^ (point p) { return x*p.y-y*p.x; }
};

int turn(point a, point b, point c) // AB 與 AC 向量外積 (為正 -> 逆時針，為負 -> 順時針)
{
    int cross = (b-a)^(c-a);
    if (cross == 0) return 0;

    return cross > 0 ? 1 : -1;
}

bool middle(point a, point b, point c) /// A 是否在 BC 之間且共線
{
    int val = (b-a)^(c-a);
    if (val != 0) return false;

    if ((b-a)*(c-a) <= 0) return true;
    else return false;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    point a1, a2, b1, b2;
    cin >> q;

    while (q--) {
        cin >> a1.x >> a1.y >> a2.x >> a2.y
            >> b1.x >> b1.y >> b2.x >> b2.y;

        if ((turn(a1, a2, b1) * turn(a1, a2, b2) > 0) ||
            (turn(b1, b2, a1) * turn(b1, b2, a2) > 0))
            cout << "NO\n";
        else if ((turn(a1, a2, b1) * turn(a1, a2, b2) < 0) &&
                 (turn(b1, b2, a1) * turn(b1, b2, a2) < 0))
            cout << "YES\n";
        else {
            if (middle(b1, a1, a2) || middle(b2, a1, a2) ||
                middle(a1, b1, b2) || middle(a2, b1, b2))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
