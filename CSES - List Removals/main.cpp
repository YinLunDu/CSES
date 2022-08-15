#include <ext/rope>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

int main()
{
    rope <int> r;
    int n;
    cin >> n;
    int i,tmp,idx;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        r.push_back(tmp);
    }
    for (i=1;i<=n;i++) {
        cin >> idx;
        idx--;
        cout << r[idx] << " ";
        r.erase(idx, 1);
    }
    cout << "\n";
    return 0;
}
