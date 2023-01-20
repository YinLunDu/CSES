#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int dsu[100005], sz[100005];

void init()
{
    fill(sz, sz+100005, 1);
    for (int i=1;i<=100000;i++) dsu[i] = i;
}
int find(int node)
{
    if (dsu[node] == node) return node;
    dsu[node] = find(dsu[node]);
    return dsu[node];
}
int merge(int a, int b)
{
    int x = find(a), y = find(b), res;
    if (x == y) return -1;
    if (sz[x] > sz[y]) {
        dsu[y] = x;
        sz[x] += sz[y];
        res = sz[x];
    } else {
        dsu[x] = y;
        sz[y] += sz[x];
        res = sz[y];
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    int num = n, mx = 1;
    int a, b;
    init();
    while (q--) {
        cin >> a >> b;
        int tmp = merge(a, b);
        if (tmp != -1) {
            mx = max(mx, tmp);
            num--;
        }
        cout << num << " " << mx << "\n";
    }
    
    return 0;
}
/*
10 3
9 5
9 6
5 9
*/