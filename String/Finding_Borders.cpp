// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void ent() {cout << "\n";}

const int mod = 998244353;
const int INF = 1e18;
/// ------- Initialization End -------

vector <int> F;

void build_F(string &s)
{
    F.resize(s.size(), -1);
    for (int i = 1; i < s.size(); i++) {
        int j = F[i - 1];
        while (j != -1 && s[i] != s[j + 1])
            j = F[j];
        if (s[i] == s[j + 1])
            F[i] = j + 1;
    }
}

signed main()
{
    IOS
    
    string s;
    cin >> s;

    build_F(s);

    vector <int> v;
    int i = s.size() - 1;
    while (F[i] != -1) {
        v.push_back(F[i]);
        i = F[i];
    }
    sort(v.begin(), v.end());
    for (int j : v)
        cout << j + 1 << " ";
    
    return 0;
}