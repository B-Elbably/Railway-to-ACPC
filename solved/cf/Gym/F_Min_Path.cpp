#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = INT64_MAX;

struct Matrix {
    int n, m;
    vector<vector<ll>> a;

    Matrix(int n, int m, ll val = 0) : n(n), m(m), a(n, vector<ll>(m, val)) {}

    static Matrix identity(int n) {
        Matrix I(n, n, INF);
        for (int i = 0; i < n; i++) I.a[i][i] = 0;
        return I;
    }

    Matrix operator*(const Matrix& B) const {
        Matrix C(n, B.m, INF);
        for (int i = 0; i < n; i++)
            for (int k = 0; k < m; k++) {
                if (a[i][k] == INF) continue;
                for (int j = 0; j < B.m; j++){
                    if (B.a[k][j] == INF) continue;
                    C.a[i][j] = min(C.a[i][j], a[i][k] + B.a[k][j]);    
                }
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
    ll n, m , k;
    cin >> n >> m >> k;
    Matrix A(n, n, INF);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        A.a[u][v] = min(A.a[u][v], w);
    }
    // for (int i = 0; i <= n; i++) A.a[i][i] = 1;
    Matrix res = Matrix::power(A, k);
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = min(ans, res.a[i][j]);
        }
    }
    if (ans == INF) cout << "IMPOSSIBLE" << "\n";
    else cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}