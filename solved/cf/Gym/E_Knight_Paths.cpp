#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint32;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

struct Matrix {
    int n, m;
    vector<vector<uint32>> a;

    Matrix(int n, int m, uint32 val = 0) : n(n), m(m), a(n, vector<uint32>(m, val)) {}

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
                    C.a[i][j] = (C.a[i][j] + a[i][k] * B.a[k][j]);
            }
        return C;
    }

    static Matrix power(Matrix base, uint32 exp) {
        Matrix result = identity(base.n);
        while (exp > 0) {
            if (exp & 1) result = result * base;
            base = base * base;
            exp >>= 1;
        }
        return result;
    }
};
bool valid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}
void solve() {
    uint32 n;
    cin >> n;
    Matrix A(65, 65);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int u = i * 8 + j;
            for (int d = 0; d < 8; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (!valid(ni, nj)) continue;
                int v = ni * 8 + nj;
                A.a[u][v] = 1;        
            }
        }
    }
    for (int i = 0; i < 64; i++) A.a[i][64] = 1;
    A.a[64][64] = 1;
    Matrix res = Matrix::power(A, n + 1);
    cout << res.a[0][64] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}

