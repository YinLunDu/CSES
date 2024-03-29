// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define STL(x) for(auto &HEHE:x) cout << HEHE << " "; cout << "\n";
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void ent() {cout << "\n";}

const int mod = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

bool check(int n, int k)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i > k)
            break;
        cnt += min(n, k / i);
        if (cnt >= n * n / 2 + 1)
            return false;
    }
    return true;
}

signed main()
{
    IOS
    
    int n;
    cin >> n;

    int l = 0, r = n * n + 1;

    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(n, mid))
            l = mid;
        else
            r = mid;
    }
    
    cout << r << "\n";

    
    return 0;
}