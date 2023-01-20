#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> G[100005];
vector <ll> order;
int vis[100005];
bool pointed[100005];

bool DFS(int node)
{
    vis[node]=2;

    bool legal=true;
    for (auto x:G[node]) {
        if (vis[x]==2)
            return false;
        else if (vis[x]==0)
            legal &= DFS(x);
    }
    vis[node]=1;
    order.push_back(node);
    return legal;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,a,b,i;

    cin >> n >> m;
    for (i=1;i<=n;i++) {vis[i]=0; pointed[i]=0;} /// initial

    for (i=1;i<=m;i++) {
        cin >> a >> b;
        G[a].push_back(b);
        pointed[b]=1;
    }

    vector <ll> head;
    head.clear();
    for (i=1;i<=n;i++) {
        if (pointed[i]==0)
            head.push_back(i);
    }

    ll sz=head.size();
    if (head.size()==0) {cout << "IMPOSSIBLE\n"; return 0;}

    bool legal=true;
    for (auto x:head) {
        legal=DFS(x);
    }


    sz=order.size();
    if (!legal || sz!=n)
        cout << "IMPOSSIBLE\n";
    else {
        reverse(order.begin(), order.end());
        for (auto x:order)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
