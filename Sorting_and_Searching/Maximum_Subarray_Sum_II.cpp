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
void enter() {cout << "\n";}

const int mod = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

int a[200005];
int pre[200005];

signed main()
{
    IOS
    
    int n, low, up;

    cin >> n >> low >> up;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    int mx = -INF;
    deque <int> dq;
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && i - dq.front() > up)
            dq.pop_front();
        
        if (i - low >= 0) {
            while (!dq.empty() && pre[dq.back()] >= pre[i - low])
                dq.pop_back();
            dq.push_back(i - low);
        }

        if (!dq.empty() && low <= i - dq.front() && i - dq.front() <= up)
            mx = max(mx, pre[i] - pre[dq.front()]);
    }

    cout << mx << "\n";
    
    return 0;
}