#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

pii p[200005];

pii operator + (pii a, pii b) { return {a.X + b.X, a.Y + b.Y}; }
pii operator - (pii a, pii b) { return {a.X - b.X, a.Y - b.Y}; }
int dot(pii p1, pii p2) { return p1.X * p2.X + p1.Y * p2.Y; }
int cross(pii p1, pii p2) { return p1.X * p2.Y - p1.Y * p2.X; }

int sign(int a)
{
    return a == 0 ? 0 : (a>0 ? 1 : -1);
}

int ori(pii a, pii b, pii c)
{
    return sign( cross(b-a, c-a) );
}

bool btw(pii a, pii b, pii c)
{
    if (sign(dot(a-c, b-c)) <= 0 && sign(cross(b-a, c-a)) == 0)
        return true;
    else
        return false;
}

bool banana(pii p1, pii p2, pii p3, pii p4)
{
    int a123 = ori(p1, p2, p3);
    int a124 = ori(p1, p2, p4);
    int a341 = ori(p3, p4, p1);
    int a342 = ori(p3, p4, p2);

    if (btw(p1, p2, p3) || btw(p1, p2, p4) || btw(p3, p4, p1) || btw(p3, p4, p2))
        return true;
    return (a123 * a124 < 0 && a341 * a342 < 0);
}

vector <pii> convex_hull(vector <pii> pts)
{
    sort(pts.begin(), pts.end());
    vector <pii> hull(1, pts[0]);

    for (int t=0; t<2; t++) {
        int sz = hull.size();
        for (int i=1; i<(int)(pts.size()); i++) {
            while ((int)hull.size() > sz && ori(hull[ hull.size() - 2 ], hull.back(), pts[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(pts[i]);
        }
        reverse(pts.begin(), pts.end());
    }
    hull.pop_back();
    return hull;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int i;
    vector<pii> pts;
    vector<pii> hull;
    for (i=1; i<=n; i++) {
        pii p;
        cin >> p.X >> p.Y;
        pts.push_back(p);
    }
    hull = convex_hull(pts);
    
    cout << hull.size() << "\n";

    for (pii it:hull) {
        cout << it.X << " " << it.Y << "\n";
    }

    return 0;
}