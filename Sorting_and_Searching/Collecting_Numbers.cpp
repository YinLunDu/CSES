#include <bits/stdc++.h>
using namespace std;

///        number  idx
vector <pair <int, int>> vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,i,tmp;
    cin >> n;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        vec.push_back({tmp, i});
    }
    sort(vec.begin(), vec.end());
    int cnt=1;
    for (i=1;i<n;i++) {
        if (vec[i].second>vec[i-1].second) continue;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
