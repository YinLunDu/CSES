/** IT IS EXTREMELY HARD **/

/**
 SIZE    NUMBERS RANGE           LENGTH
 9       10^0 ~ 10^1-1       (10^1-10^0)*1
           1  ~   9
*********************************************
 180     10^1 ~ 10^2-1       (10^2-10^1)*2
          10  ~   99
 **/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int fastpow(int a, int b)
{
    int res=a, ans=1;
    while (b!=0) {
        if (b&1)
            ans*=res;
        res*=res;
        b/=2;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[20], i;

    for (i=1;i<=18;i++)
        arr[i]=( fastpow(10,i) - fastpow(10,i-1) )*i;
/// array records "each size of the number" of the length
    int q;
    cin >> q;
    int n;
    while (q--) {
        cin >> n;
        int tmp=0;
        int i=1;
        while (tmp+arr[i]<n) {
            tmp+=arr[i];
            i++;
        }
        int num=fastpow(10, i-1)-1;
/// num -->  prev(the first number of that group)

        tmp=n-tmp;
        if (tmp%i==0)
            num+=tmp/i;
        else
            num+=tmp/i+1;
/// num -->  the whole number of the answer

        tmp=(tmp-1)%i;
/// tmp -->  the index of number
        string s=to_string(num);
        cout << s[tmp] << "\n";
    }

    return 0;
}
