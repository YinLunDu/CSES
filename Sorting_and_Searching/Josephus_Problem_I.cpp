#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

struct _BIT
{
    int bit[200005];
    void init(int n) {
        for (int i=0; i<=n; i++) bit[i] = 0;
    }
    void update(int idx, int val) {
        while (idx <= 200000) {
            bit[idx] += val;
            idx += (idx & -idx);
        } 
    }
    int query(int idx) {
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= (idx & -idx);
        }
        return res;
    }
} BIT;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k = 1, i;

    cin >> n;

    BIT.init(n);
    for (i=1; i<=n; i++)
        BIT.update(i, 1);
    
    int pos = 1, cnt = n;
    for (i=1; i<=n; i++) {
        int res = BIT.query(n) - BIT.query(pos-1);
        int step = k;
        if (res <= step) {
            step = step - res;
            pos = 1;
            step = step % cnt + 1;

            int tmp = BIT.query(pos - 1);
            int l = pos, r = n;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (BIT.query(mid) - tmp >= step)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            pos = l;
        } else {
            step += 1;
            int tmp = BIT.query(pos - 1);
            int l = pos, r = n;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (BIT.query(mid) - tmp >= step)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            pos = l;
        }

        cout << pos << " ";
        BIT.update(pos, -1);

        cnt--;
    }
    cout << "\n";
    
    return 0;
}