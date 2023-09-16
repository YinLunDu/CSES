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

signed main()
{
    IOS
    
    int n;
    cin >> n;

    int ans = 0;
    
    for (int i = 0; i <= 50; i++) {
        if (n < (1ll << i))
            break;

        int len = n - ((1ll << i) - 1);

        ans += (1ll << i) * (len / (1ll << (i + 1)));
        
        int less = min((1ll << i), len % (1ll << (i + 1)));

        ans += max(0ll, less);
    }

    cout << ans << "\n";
    
    return 0;
}