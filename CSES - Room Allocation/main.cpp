#include <bits/stdc++.h>

using namespace std;

struct item
{
    int a,b;
    int idx;
    int num;
}arr[200005];

priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;

bool cmp1(struct item x, struct item y)
{
    if (x.a==y.a)
        return x.b<y.b;
    else
        return x.a<y.a;
}

bool cmp2(struct item x, struct item y)
{
    return x.idx<y.idx;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,i,x,y;
    cin >> n;
    for (i=1;i<=n;i++) {
        cin >> x >> y;
        arr[i].idx=i;
        arr[i].a=x;
        arr[i].b=y;
    }
    int room=1;
    sort(arr+1, arr+n+1, cmp1);
    for (i=1;i<=n;i++) {
        if (pq.size()==0) {
            arr[i].num=room;
            pq.push({arr[i].b, arr[i].num});
            room++;
        } else {
            pair <int, int> up=pq.top();
            if (up.first<arr[i].a) {
                pq.pop();
                arr[i].num=up.second;
                pq.push({arr[i].b, arr[i].num});
            } else {
                arr[i].num=room;
                pq.push({arr[i].b, arr[i].num});
                room++;
            }
        }
    }
    sort(arr+1, arr+n+1, cmp2);
    cout << room-1 << "\n";
    for (i=1;i<=n;i++)
        cout << arr[i].num << " ";
    cout << "\n";
    return 0;
}
