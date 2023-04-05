#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

struct line
{
    int a, b;
    line(int _a, int _b): a(_a), b(_b){}
    int operator()(int x)
    {
        return a*x + b;
    }
};

int s[200005], f[200005];
int dp[200005];

bool check(line l1, line l2, line l3)
{
    if ((l1.a - l2.a) * (l3.b - l1.b) <= (l1.a - l3.a) * (l2.b - l1.a))
        return true;
    else
        return false;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, i;
    
    cin >> n >> x;
    for (i=1; i<=n; i++)
        cin >> s[i];
    
    for (i=1; i<=n; i++) {
        cin >> f[i];
        f[i] *= -1;
    }
    
    deque <line> dq;
    dq.push_back({-x, 0});

    for (i=1; i<=n; i++) {
        while (dq.size() >= 2 && dq[0](s[i]) <= dq[1](s[i]))
            dq.pop_front();
        dp[i] = dq[0](s[i]);
        line l(f[i], dp[i]);

        while (dq.size() >= 2 && check(dq[dq.size()-2], dq[dq.size()-1], l)) {
            dq.pop_back();
        }
        dq.push_back(l);
    }
    cout << -dp[n] << "\n";

    return 0;
}