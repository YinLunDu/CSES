#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll input[200002];
vector <ll> tmp;
ll dp[200002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, i;
    cin >> n;
    for (i=1;i<=n;i++)
        cin >> input[i];

    for (i=1;i<=n;i++) {
        ll idx=lower_bound(tmp.begin(), tmp.end(), input[i])-tmp.begin();
        if (idx==tmp.size()) tmp.push_back(input[i]);
        else {
            tmp[idx]=input[i];
        }
    }

    cout << tmp.size() << "\n";

    return 0;
}
