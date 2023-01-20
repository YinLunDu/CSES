#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int n,i,ans=1e9,tmp,sum=0;
    cin >> n;
    vector <int> vec;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        sum+=tmp;
        vec.push_back(tmp);
    }
    long long int a,b,now,j;
    for (i=0;i< (1<<n);i++) {
        a=0; now=i; j=0;
        while (now>0) {
            if (now&1) {
                a+=vec[j];
            }
            now/=2;
            j++;
        }
        b=sum-a;
        if (abs(a-b)<ans) ans=abs(a-b);
        //cout << abs(a-b) << " ";
    }
    cout << ans << "\n";
    return 0;
}
