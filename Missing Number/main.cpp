#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> vec;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,tmp,i;
    cin >> n;
    for (i=1;i<=n-1;i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    for (i=1;i<=n;i++) {
        if (vec[i-1]!=i) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
