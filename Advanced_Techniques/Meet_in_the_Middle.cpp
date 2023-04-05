/// 折半枚舉
#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, mid, ans;
int arr[50];
vector <int> v;

void dfs(int idx, int sum)
{
    if (idx == mid+1) {
        v.push_back(sum);
        return;
    }

    dfs(idx + 1, sum);
    dfs(idx + 1, sum + arr[idx]);
}

void match(int idx, int sum)
{
    if (idx == n+1) {
        ans += upper_bound(v.begin(), v.end(), m-sum) - lower_bound(v.begin(), v.end(), m-sum);
        return;
    }

    match(idx + 1, sum);
    match(idx + 1, sum + arr[idx]);
}

/// 1 ~ mid   mid+1 ~ n

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int i;
    for (i=1;i<=n;i++)
        cin >> arr[i];
    
    mid = (1+n)/2;
    dfs(1, 0);

    sort(v.begin(), v.end());
    ans = 0;
    match(mid+1, 0);

    cout << ans << "\n";

    return 0;
}