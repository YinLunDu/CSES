/**
 The 11th Gray code number:

 11 in Binary: 1011
 Right shift: 1011 >> 1 = 0101
 XOR: 1011 ^ 0101 = 1110
 **/
#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,i;
    cin >> n;
    for (i=0;i< (1 << n);i++) {
        int tmp=i^(i>>1);

        vector <int> vec; int cnt=0;
        while (tmp!=0) {
            if (tmp&1) {
                vec.push_back(1);
                cnt++;
            } else {
                vec.push_back(0);
                cnt++;
            }
            tmp/=2;
        }
        while (cnt<n) {
            vec.push_back(0);
            cnt++;
        }
        for (auto it:vec)
            cout << it;
        cout << "\n";
    }
    return 0;
}
