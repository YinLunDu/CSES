/**
 find the rules of the test data
 let the chessboard is k*k
 then the answer is

    ALL    - ATTACK
 C(k*k)(2) -    ?

 We can know that ?=4*(k-1)*(k-2) !!!
 **/
#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, i;
    cin >> n;
    for (i=1;i<=n;i++)
        cout << (i*i)*(i*i-1)/2-4*(i-1)*(i-2) << "\n";
    return 0;
}
