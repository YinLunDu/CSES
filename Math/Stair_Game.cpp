// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define STL(x) for (auto &HEHE : x) cout << HEHE << " "; cout << "\n";
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void ent() {cout << "\n";}

const int mod = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

int a[200005];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int S = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0)
            S ^= a[i];
    }
    if (S > 0)
        cout << "first\n";
    else
        cout << "second\n";
}

signed main()
{
    IOS
    int t = 1;
    cin >> t;

    while (t--)
        solve();
    
    return 0;
}