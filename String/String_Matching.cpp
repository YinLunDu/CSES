// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0)
#define STL(x) for (auto &HEHE : x) cout << HEHE << " "; cout << "\n";
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void ent() {cout << "\n";}

const int P = 1e6 + 3;
const int M = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

vector <int> Z;

void calc_Z(string &s)
{
    Z.resize(s.size(), 0);
    for (int i = 1, l = 0, r = 0; i < (int)s.size(); i++) {
        if (i <= r)
            Z[i] = min(Z[i - l], r - i + 1);
        while (i + Z[i] < (int)s.size() && s[Z[i]] == s[i + Z[i]])
            Z[i]++;
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
}

signed main()
{
    IOS;
    string s, t;
    cin >> s >> t;
    string res = t + '$' + s;

    calc_Z(res);
    
    int cnt = 0;
    for (int i = 0; i < Z.size(); i++)
        if (Z[i] == t.size())
            cnt++;
    cout << cnt << "\n";
}

/*
vector <int> F;
void build_F(string &t)
{
    F.resize(t.size(), -1);
    for (int i = 1; i < t.size(); i++) {
        int j = F[i - 1];
        while (j != -1 && t[i] != t[j + 1])
            j = F[j];
        if (t[i] == t[j + 1])
            F[i] = j + 1;
    }
}

int KMP(string &s, string &t)
{
    int cnt = 0;
    for (int i = 0, j = -1; i < s.size(); i++) {
        while (j != -1 && s[i] != t[j + 1])
            j = F[j];
        if (s[i] == t[j + 1])
            j++;
        if (j + 1 == t.size()) {
            cnt++;
            j = F[j];
        }
    }
    return cnt;
}

signed main()
{
    IOS;
    string s, t;
    cin >> s >> t;

    build_F(t);
    int ans = KMP(s, t);
    cout << ans << "\n";
}
*/

/*
int rhs[1000005], rht[1000005];

void build(string &s, string &t)
{
    rhs[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); i++) {
        rhs[i] = rhs[i - 1] * P + s[i] - 'a' + 1;
        rhs[i] %= M;
    }
    rht[0] = t[0] - 'a' + 1;
    for (int i = 1; i < t.size(); i++) {
        rht[i] = rht[i - 1] * P + t[i] - 'a' + 1;
        rht[i] %= M;
    }
}

int ppow[1000005];

int query(int l, int r)
{
    int res = rhs[r] - (l > 0 ? rhs[l - 1] * ppow[r - l + 1] : 0);
    res = (res % M + M) % M;
    return res;
}

signed main()
{
    IOS;
    
    string s, t;
    cin >> s >> t;

    if (s.size() < t.size()) {
        cout << 0 << "\n";
        return 0;
    }

    ppow[0] = 1;
    for (int i = 1; i <= s.size(); i++) {
        ppow[i] = (ppow[i - 1] * P) % M;
    }

    build(s, t);

    int T = rht[t.size() - 1];
    int ans = 0;
    for (int i = 0; i + t.size() - 1 < s.size(); i++) {
        if (query(i, i + t.size() - 1) == T) {
            // dbg(i, query(i, i + t.size() - 1), T);
            ans++;
        }
    }
    cout << ans << "\n";
    
    return 0;
}
*/