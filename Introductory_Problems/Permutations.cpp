#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    if (n==1)
        cout << "1\n";
    else if (n<=3)
        cout << "NO SOLUTION\n";
    else {
        deque <ll> dq;
        dq.push_back(3);
        dq.push_back(1);
        dq.push_back(4);
        dq.push_back(2);
        ll now=5;
        while (now<=n) {
            if (now%2==0) {
                dq.push_front(now);
            } else {
                dq.push_back(now);
            }
            now++;
        }
        for (auto it:dq)
            cout << it << " ";
        cout << "\n";
    }
    return 0;
}
