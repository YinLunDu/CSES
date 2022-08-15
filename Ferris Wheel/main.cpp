#include <bits/stdc++.h>

using namespace std;

vector <int> vec;

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, i, tmp;
    cin >> n >> x;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end(), cmp);
    int head=0, tail=n-1;
    int cnt=0;
    while (head<tail) {
        if (vec[head]+vec[tail]>x) {
            head++;
            cnt++;
        } else {
            head++;
            tail--;
            cnt++;
        }
    }

    if (head==tail) cnt++;

    cout << cnt << "\n";
    return 0;
}
