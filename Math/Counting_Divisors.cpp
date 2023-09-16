#include <bits/stdc++.h>
#define int long long
using namespace std;

bool is_prime[2750135];
int primes[200005];
int lpf[2750135];

/// The 199999-th of the prime is 2750131
void init() {
    fill(is_prime, is_prime + 2750135, true);
    int idx = 0;
    for (int i = 2; i <= 2750131; i++) {
        if (is_prime[i]) {
            primes[++idx] = i;
            lpf[i] = i;
        }
        for (int j = 1; j <= idx; j++) {
            if (primes[j] * i > 2750131) break;
            is_prime[primes[j] * i] = false;
            lpf[primes[j] * i] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}

int prime_factor(int n)
{
    int ans = 1;
    while (n != 1) {
        int tmp = lpf[n], cnt = 0;
        while (n % tmp == 0) {
            n /= tmp;
            cnt++;
        }
        ans *= cnt + 1;
    }
    return ans;
}

signed main()
{
    int n, q;

    init();

    cin >> q;
    while (q--) {
        cin >> n;
        cout << prime_factor(n) << "\n";
    }

    return 0;
}
