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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), c(n);
    for (auto &x : a) cin >> x;
    for (auto &x : c) cin >> x;
    int p, q, r;
    cin >> p >> q >> r;
    if (k < n) {
        cout << a[k] << endl;
        return;
    }
    int m = n + 3;
    Matrix A(m, m);
    for (int j = 0; j < n; ++j) {
        A.a[0][j] = c[j];
    }
    A.a[0][n] = p;
    A.a[0][n + 1] = q;
    A.a[0][n + 2] = r;

    for (int i = 1; i < n; ++i) {
        A.a[i][i - 1] = 1;
    }
    A.a[n][n] = 1;
    A.a[n + 1][n] = 1;
    A.a[n + 1][n + 1] = 1;
    
    A.a[n + 2][n] = 1;
    A.a[n + 2][n + 1] = 2;
    A.a[n + 2][n + 2] = 1;

    A = Matrix::power(A, k - n + 1);

    Matrix V(m, 1);
    for (int i = 0; i < n; ++i) {
        V.a[i][0] = a[n - 1 - i] % MOD;
    }
    V.a[n][0] = 1;
    V.a[n + 1][0] = n;
    V.a[n + 2][0] = (n * n) % MOD;

    Matrix ans = A * V;
    cout << (ans.a[0][0] % MOD + MOD) % MOD << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
