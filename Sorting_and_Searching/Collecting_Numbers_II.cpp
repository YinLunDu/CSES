#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int n, arr[200005], pos[200005];

int checkpre(int x, int from, int to)
{
    if (x == 1) return 0;
    if (from < pos[x-1] && pos[x-1] < to)
        return -1;
    if (to < pos[x-1] && pos[x-1] < from)
        return 1;
    return 0;
}

int checknext(int x, int from, int to)
{
    if (x == n) return 0;
    if (from < pos[x+1] && pos[x+1] < to)
        return 1;
    if (to < pos[x+1] && pos[x+1] < from)
        return -1;
    return 0;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q, i;
    cin >> n >> q;
    for (i=1; i<=n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int res = 1;
    for (i=1; i<=n-1; i++) {
        if (pos[i] > pos[i+1])
            res++;
    }

    pii a, b;
    while (q--) {
        cin >> a.first >> b.first;
        a.second = arr[a.first];
        b.second = arr[b.first];
        if (a.second > b.second)
            swap(a, b);
///  first : pos ,    second : val
        if (a.second + 1 == b.second) {
            if (a.first < b.first)
                res++;
            else
                res--;
            res += checkpre(a.second, a.first, b.first);
            res += checknext(b.second, b.first, a.first);
        } else {
            res += checkpre(a.second, a.first, b.first);
            res += checknext(a.second, a.first, b.first);

            res += checkpre(b.second, b.first, a.first);
            res += checknext(b.second, b.first, a.first);
        }

        swap(arr[a.first], arr[b.first]);
        swap(pos[a.second], pos[b.second]);

        cout << res << "\n";
    }
    
    return 0;
}