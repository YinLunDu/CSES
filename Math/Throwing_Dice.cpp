#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define matrix array<array<int, 6>, 6>
using namespace std;

const int MOD = 1e9+7;

matrix mul(matrix a, matrix b)
{
    matrix c;
    for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++) {
            c[i][j] = 0;
            for (int k=0; k<6; k++) {
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

    int k;
    cin >> k;

    matrix A, F;
    fill(&A[0][0], &A[0][0] + 6*6, 0);
    for (int i=0; i<6; i++)
        A[i][i] = 1;
    
    F[0][0] = 1; F[0][1] = 1; F[0][2] = 1; F[0][3] = 1; F[0][4] = 1; F[0][5] = 1;
    F[1][0] = 1; F[1][1] = 0; F[1][2] = 0; F[1][3] = 0; F[1][4] = 0; F[1][5] = 0;
    F[2][0] = 0; F[2][1] = 1; F[2][2] = 0; F[2][3] = 0; F[2][4] = 0; F[2][5] = 0;
    F[3][0] = 0; F[3][1] = 0; F[3][2] = 1; F[3][3] = 0; F[3][4] = 0; F[3][5] = 0;
    F[4][0] = 0; F[4][1] = 0; F[4][2] = 0; F[4][3] = 1; F[4][4] = 0; F[4][5] = 0;
    F[5][0] = 0; F[5][1] = 0; F[5][2] = 0; F[5][3] = 0; F[5][4] = 1; F[5][5] = 0;

    while (k > 0) {
        if (k & 1) A = mul(A, F);
        F = mul(F, F);
        k >>= 1;
    }

    cout << (A[5][0] * 16 + A[5][1] * 8 + A[5][2] * 4 + A[5][3] * 2 + A[5][4] * 1 + A[5][5] * 1) % MOD << "\n";
    
    return 0;
}