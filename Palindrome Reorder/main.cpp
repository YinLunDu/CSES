#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int num[27],i,j;
    fill(num, num+27, 0);
    for (auto it:s)
        num[it-'A']++;

    int cnt=0; /// odd amount
    int idx;
    for (i=0;i<=25;i++)
        if (num[i]%2==1) {
            cnt++;
            idx=i;
        }

    if (cnt>1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for (i=0;i<=25;i++) {
        char ch='A'+i;
        for (j=1;j<=num[i]/2;j++)
            cout << ch;
    }

    if (cnt==1) {
        char ch='A'+idx;
        cout << ch;
    }

    for (i=25;i>=0;i--) {
        char ch='A'+i;
        for (j=1;j<=num[i]/2;j++)
            cout << ch;
    }
    return 0;
}
