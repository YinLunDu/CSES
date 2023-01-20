#include <bits/stdc++.h>

using namespace std;

int arr[200005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,i;

    multiset <int> a,b;

    cin >> n >> k;

    for (i=1;i<=n;i++) {
        cin >> arr[i];

        if (i>k) {
            if (a.find(arr[i-k])!=a.end())
                a.erase(a.find(arr[i-k]));
            else
                b.erase(b.find(arr[i-k]));
        }

        if (a.size()>=b.size()+2) {
            auto it=a.rbegin();
            int x=*it;
            a.erase(a.find(x));
            b.insert(x);
        } else if (a.size()<b.size()) {
            auto it=b.begin();
            int x=*it;
            b.erase(b.find(x));
            a.insert(x);
        }


        if (!a.empty()) {
            int p=*a.rbegin();

            if (arr[i]<=p)  a.insert(arr[i]);
            else  b.insert(arr[i]);

        } else {
            a.insert(arr[i]);
        }

        if (a.size()>=b.size()+2) {
            auto it=a.rbegin();
            int x=*it;
            a.erase(a.find(x));
            b.insert(x);
        } else if (a.size()<b.size()) {
            auto it=b.begin();
            int x=*it;
            b.erase(b.find(x));
            a.insert(x);
        }

        //cout << a.size() << " " << b.size() << "\n";
        if (i>=k) cout << *a.rbegin() << " ";
    }

    return 0;
}
