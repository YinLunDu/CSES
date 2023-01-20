#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

struct item
{
    int a, b, c;
}arr[200005];

bool cmp(item x, item y) { return x.c < y.c; }

int dsu[200005];
int n, m;

void init()
{
    int i;
    for (i=1;i<=n;i++) {
        dsu[i] = i;
    }
}

int find(int node)
{
    if (dsu[node] == node) return node;
    dsu[node] = find(dsu[node]);
    return dsu[node];
}

void merge(int x, int y)
{
    int xx = find(x);
    int yy = find(y);
    dsu[xx] = yy;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int i, sum=0;
    for (i=1;i<=m;i++)
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    
    sort(arr+1, arr+m+1, cmp);

    init();
    for (i=1;i<=m;i++) {
        if (find(arr[i].a) != find(arr[i].b)) {
            sum += arr[i].c;
            merge(arr[i].a, arr[i].b);
        }
    }

    bool able = true;
    int tmp = find(1);
    for (i=2;i<=n;i++) {
        if (find(i) != tmp) {
            able = 0;
            break;
        }
    }
    if (able)
        cout << sum << "\n";
    else
        cout << "IMPOSSIBLE\n";
    
    return 0;
}