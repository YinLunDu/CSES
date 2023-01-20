#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector <int> v;
    int tmp;
    int i;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int L=1, R=1e18;
    int mid, sum;
    bool done;
    while (L<=R) {
        mid=(L+R)/2;
        done=false;
        sum=0;
        for (auto it:v) {
            sum+=mid/it;
            if (sum>=t) {
                done=true;
                break;
            }
        }
        if (done==true)
            R=mid-1;
        else
            L=mid+1;
    }

    cout << L << "\n";
    return 0;
}
