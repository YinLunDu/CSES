#include <bits/stdc++.h>

using namespace std;

struct point {
    long long x;
    long long y;
    point operator + (point p) { return {x+p.x, y+p.y}; }
    point operator - (point p) { return {x-p.x, y-p.y}; }

    double operator * (point p) { return x*p.x+y*p.y; }
    long long operator ^ (point p) { return x*p.y-p.x*y; }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    point a,b,c;
    int q;
    cin >> q;
    while (q--) {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        point tmp1=b-a, tmp2=c-a;
        if ((tmp1^tmp2)>0) cout << "LEFT\n";
        if ((tmp1^tmp2)<0) cout << "RIGHT\n";
        if ((tmp1^tmp2)==0) cout << "TOUCH\n";
    }


    return 0;
}
