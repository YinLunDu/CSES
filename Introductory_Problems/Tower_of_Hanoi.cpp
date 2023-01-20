#include <bits/stdc++.h>

using namespace std;

vector <pair<int,int>> step;

void hanoi(int disk, int from, int to, int pass)
{
    if (disk==1) {
        step.push_back({from, to});
        return;
    } else {
        hanoi(disk-1, from, pass, to);
        step.push_back({from, to});
        hanoi(disk-1, pass, to, from);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    hanoi(n, 1, 3, 2);
    cout << step.size() << "\n";
    for (auto it:step) {
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}
