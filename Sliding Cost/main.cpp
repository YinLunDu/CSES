#include <bits/stdc++.h>
#define int long long

using namespace std;

int arr[200005];

void balance(multiset <int> &a, multiset <int> &b)
{
    while (a.size()>b.size()) {
        b.insert(*a.rbegin());
        a.erase(a.find(*a.rbegin()));
    }
    while (a.size()<b.size()) {
        a.insert(*b.begin());
        b.erase(b.find(*b.begin()));
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,i;
    cin >> n >> k;

    for (i=1;i<=n;i++)
        cin >> arr[i];

    if (k==1) {
        for (i=1;i<=n;i++)
            cout << "0 ";
        cout << "\n";
        return 0;
    }


    multiset <int> a,b;

    int suma=0, sumb=0;

    for (i=1;i<=n;i++) {
        if (a.empty() || arr[i]<=*a.rbegin()) {
            a.insert(arr[i]);
            suma+=arr[i];
        } else {
            b.insert(arr[i]);
            sumb+=arr[i];
        }

        if (i>=k+1) {
            if (a.empty() || arr[i-k]>*a.rbegin()) {
                b.erase(b.find(arr[i-k]));
                sumb-=arr[i-k];
            } else {
                a.erase(a.find(arr[i-k]));
                suma-=arr[i-k];
            }
        }

        while (a.size()>b.size()) {
            sumb+=*a.rbegin();
            suma-=*a.rbegin();
            b.insert(*a.rbegin());
            a.erase(a.find(*a.rbegin()));
        }
        while (a.size()<b.size()) {
            suma+=*b.begin();
            sumb-=*b.begin();
            a.insert(*b.begin());
            b.erase(b.find(*b.begin()));
        }

        if (i>=k) {
            int mid=*a.rbegin();

            if (a.size()==b.size())
                cout << sumb-suma << " ";
            else
                cout << sumb-suma+mid << " ";
        }
    }
    cout << "\n";
    return 0;
}
