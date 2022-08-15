#include <bits/stdc++.h>
#define int long long

using namespace std;

int pre[200005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q,i,tmp;
    cin >> n >> q;
    fill(pre, pre+200005, 0);
    pre[0]=0;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        pre[i]=pre[i-1]+tmp;
    }
    int a,b;
    while (q--) {
        cin >> a >> b;
        cout << pre[b]-pre[a-1] << "\n";
    }
    return 0;
}
