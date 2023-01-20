#include <bits/stdc++.h>

using namespace std;

vector <int> d;
vector <int> sz;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    int i,tmp;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        d.push_back(tmp);
    }
    for (i=1;i<=m;i++) {
        cin >> tmp;
        sz.push_back(tmp);
    }

    sort(d.begin(), d.end());
    sort(sz.begin(), sz.end());

    int h1=0, h2=0;
    int cnt=0;
    while (h1<=n-1 && h2<=m-1) {
        if (d[h1]-k<=sz[h2] && sz[h2]<=d[h1]+k) {
            cnt++;
            h1++;
            h2++;
        } else if (d[h1]-k>sz[h2]) {
            h2++;
        } else {
            h1++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
