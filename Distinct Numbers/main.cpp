#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, i, tmp;
    vector <int> vec;
    cin >> n;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    int cnt=1, pre;
    pre=vec[0];
    for (i=1;i<=n-1;i++) {
        if (vec[i]==pre) continue;

        pre=vec[i];
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
