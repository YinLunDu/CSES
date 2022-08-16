#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);

    vector <char> v;
    for (auto it:s)
        v.push_back(it);
    sort(v.begin(), v.end());

    vector <string> ans;

    do {
        string tmp;
        for (auto it:v)
            tmp+=it;
        ans.push_back(tmp);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans.size() << "\n";
    for (auto it:ans)
        cout << it << "\n";

    return 0;
}
