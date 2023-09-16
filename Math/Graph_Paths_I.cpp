#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define matrix array<array<int, 101>, 101>
using namespace std;

const int MOD = 1e9 + 7;

matrix A, F;

matrix mul(matrix a, matrix b, int N)
{
    matrix c;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            c[i][j] = 0;
            for (int k = 1; k <= N; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= MOD;
            }
        }
    }
    return c;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 100; i++)
        A[i][i] = 1;

    int n, m, k;
    cin >> n >> m >> k;
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        F[a][b]++;
    }

    while (k > 0)
    {
        if (k & 1)
            A = mul(A, F, n);
        F = mul(F, F, n);
        k >>= 1;
    }
    cout << A[1][n] << "\n";

    return 0;
}