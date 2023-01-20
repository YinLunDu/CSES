#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    ll sz=s.size();
    char pre='0';
    ll mx=0, i;
    ll cnt=0;
    for (i=0;i<sz;i++) {
        if (pre!=s[i]) {
            mx=max(mx, cnt);
            pre=s[i];
            cnt=1;
        } else {
            cnt++;
        }
    }
    mx=max(mx, cnt);
    cout << mx << "\n";
    return 0;
}
