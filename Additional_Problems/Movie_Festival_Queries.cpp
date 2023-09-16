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

int dp[20][1000005];
pii a[1000005];

signed main()
{
    IOS
    
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        dp[0][a[i].second] = max(dp[0][a[i].second], a[i].first);
    }

    for (int i = 1; i <= 1000000; i++) {
        dp[0][i] = max(dp[0][i], dp[0][i - 1]);
    }

    for (int lg = 1; lg < 20; lg++) {
        for (int i = 1; i <= 1000000; i++) {
            dp[lg][i] = dp[lg - 1][dp[lg - 1][i]];
        }
    }

    int l, r;
    while (q--) {
        cin >> l >> r;
        int cnt = 0;
        int now = r;
        for (int lg = 19; lg >= 0; lg--) {
            if (dp[lg][now] >= l) {
                now = dp[lg][now];
                cnt += (1 << lg);
            }
        }
        cout << cnt << "\n";
    }
    
    return 0;
}