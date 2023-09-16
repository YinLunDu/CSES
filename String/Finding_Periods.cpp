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
/// ------- Initialization End -------

const int p = 1e6 + 3;
const int mod = 1e9 + 7; /// 不能超過 3e9 -> 會 overflow

int pow_p[1000005];
vector <int> rh;
void build(string &s)
{
    rh.resize(s.size() + 1);
    pow_p[0] = 1;
    for (int i = 1; i <= s.size(); i++)
        pow_p[i] = (pow_p[i - 1] * p) % mod;
    
    rh[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); i++) {
        rh[i] = rh[i - 1] * p + (s[i] - 'a' + 1);
        rh[i] %= mod;
    }
}

int query(int l, int r)
{
    int res = rh[r] - (l > 0 ? rh[l - 1] * pow_p[r - l + 1] : 0);
    res = (res % mod + mod) % mod;
    return res;
}

signed main()
{
    IOS
    
    string s;
    cin >> s;

    build(s);

    for (int i = 1; i <= (int)s.size(); i++) {
        bool fail = false;
        int id = 0;
        int all_cnt = query(0, i - 1);
        while (id + i - 1 < s.size()) {
            /// [id, id + i)
            if (query(id, id + i - 1) != all_cnt) {
                fail = true;
                break;
            }
            id += i;
        }
        if (!fail && id < s.size()) {
            if (query(id, s.size() - 1) != query(0, (int)s.size() - 1 - id))
                fail = true;
        }
        if (!fail)
            cout << i << " ";
    }

    return 0;
}