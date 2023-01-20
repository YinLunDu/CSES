/**
 * @brief 排序
 * 
 * 我們先假設第一個無法表達的答案為 res
 * 先排序
 * 再從 res = 1 開始檢查 ...
 * 檢查流程：
 * 如果 res < arr[i]，則輸出 res ........(1)
 * 否則 res 加上 arr[i] .................(2)
 * 
 * (1)
 * 因為 [1:res-1] 已經可以被 arr[1:(i-1)] 表達
 * 則代表 res - 1 = arr[1:(i-1)]
 * 因此 arr[1:(i-1)] 最多只能表達 res - 1
 * 所以若 arr[i] 大於 res 時，則 res 不可能被表達
 * 
 * (2)
 * [0:(res-1)] 可以被 arr[1:(i-1)] 表達
 * [0:(res-1)] 加上 arr[i] 得到 [arr[i] : (res+arr[i]-1)]
 * 
 * 因為 arr[i] <= res
 * 
 * -> [0:(res-1)] 與 [arr[i] : (res+arr[i]-1)]
 *    取聯集得到 [0:(res+arr[i]-1)]
 * 
 * 因此 res + arr[i] 為下個要檢查的對象
 * 
 */
#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,i;
    cin >> n;
    vector <int> v;
    int tmp;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int sum=0;
    for (i=0;i<n;i++) {
        if (sum+1<v[i])
            break;
        sum+=v[i];
    }
    cout << sum+1 << "\n";
    return 0;
}
