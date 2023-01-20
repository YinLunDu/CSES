#include <bits/stdc++.h>
#define int long long

using namespace std;

int cnt[1000005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int i,j,mx=0;

    fill(cnt, cnt+1000005, 0);
    int tmp;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        mx=max(mx, tmp);
        cnt[tmp]++;
    }


    for (i=mx;i>=1;i--) {
        int tmp=0;
        for (j=i;j<=1000000;j+=i) {
            tmp+=cnt[j];
        }
        if (tmp>=2)
            break;
    }

    cout << i << "\n";

    return 0;
}
