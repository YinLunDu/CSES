#include <bits/stdc++.h>
#define int long long

using namespace std;

int cnt[1000005];

signed main() {
    int n;
    cin >> n;
    int mx = 0;

    fill(cnt, cnt + 1000005, 0);
    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        mx = max(mx, tmp);
        cnt[tmp]++;
    }

    int ans = -1;
    for (int i = mx; i >= 1; i--) {
        int tmp = 0;
        for (int j = i; j <= 1000000; j += i)
            tmp += cnt[j];
        if (tmp >= 2) {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}
