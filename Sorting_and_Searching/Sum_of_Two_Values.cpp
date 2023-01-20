#include <bits/stdc++.h>

using namespace std;

pair <int, int> arr[200005];

bool cmp(pair <int, int> p1, pair <int, int> p2)
{
    return p1.second<p2.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,x,i,L,R;
    cin >> n >> x;
    for (i=0;i<n;i++) {
        arr[i].first=i+1;
        cin >> arr[i].second;
    }
    sort(arr, arr+n, cmp);
    L=0; R=n-1;
    bool success=0;
    while (L<R) {
        if (arr[L].second+arr[R].second==x) {
            cout << arr[L].first << " " << arr[R].first << "\n";
            success=1;
            break;
        } else if (arr[L].second+arr[R].second<x) {
            L++;
        } else {
            R--;
        }
    }
    if (success==0) cout << "IMPOSSIBLE\n";
    return 0;
}
