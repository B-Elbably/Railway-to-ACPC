#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using ll = long long;
const ll MOD = 1e9 + 7;

struct Matrix {
    int n, m;
    vector<vector<ll>> a;

    Matrix(int n, int m, ll val = 0) : n(n), m(m), a(n, vector<ll>(m, val)) {}

    static Matrix identity(int n) {
        Matrix I(n, n);
        for (int i = 0; i < n; i++) I.a[i][i] = 1;
        return I;
    }

    Matrix operator*(const Matrix& B) const {
        Matrix C(n, B.m);
        for (int i = 0; i < n; i++)
            for (int k = 0; k < m; k++) {
                if (!a[i][k]) continue;
                for (int j = 0; j < B.m; j++)
                    C.a[i][j] = (C.a[i][j] + a[i][k] * B.a[k][j]) % MOD;
            }
        return C;
    }

    static Matrix power(Matrix base, ll exp) {
        Matrix result = identity(base.n);
        while (exp > 0) {
            if (exp & 1) result = result * base;
            base = base * base;
            exp >>= 1;
        }
        return result;
    }
};

void solve() {
    int l, r;
    cin >> l >> r;

    Matrix A(2, 2);
    A.a = {{1, 1}, {1, 0}};
    int res = Matrix::power(A, r + 1).a[0][0];
    res -= Matrix::power(A, l).a[0][0];
    res = (res % MOD + MOD) % MOD;
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}