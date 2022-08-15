#include <bits/stdc++.h>
#define ll long long

using namespace std;

void fun(ll n)
{
    cout << n << " ";
    if (n==1) {
        return;
    } else if (n%2==0) {
        fun(n/2);
    } else {
        fun(n*3+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    fun(n);
    return 0;
}
