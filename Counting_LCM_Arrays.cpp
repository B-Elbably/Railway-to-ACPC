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

vector<int> factorize(int n) {
    vector<int> factors;
    int m = n;
    for (int i = 2; i * i <= m; ++i) {
        int cnt = 0;
        while (n % i == 0) {
            // factors.push_back(i);
            n /= i;
            cnt++;
        }
        if (cnt) factors.push_back(cnt);
    }
    if (n > 1) factors.push_back(1);
    // factors.erase(unique(all(factors)), factors.end());
    // factors.push_back(1);
    return factors;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> factors = factorize(k);
    // cout << factors.size() << endl;
    int ans = 1;
    for (int e: factors) {
        // cout << e << endl;
        Matrix A(2, 2);
        A.a = {{1, 1}, {e, 0}};
        A = Matrix::power(A, n + 1);
        ans *= A.a[0][0] % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
