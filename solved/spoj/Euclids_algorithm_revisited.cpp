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

int gcd(int a, int b) {
    int cnt = 0;
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
        cnt++;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    if (n == 1) {
        cout << 2 << endl;
        return;
    }
    // vector<int> arr(100, 1000000);
    // for (int i = 1; i <= 1000; ++i) {
    //     for (int j = 1; j <= 1000; ++j) {
    //         int cnt = gcd(i, j);
    //         arr[cnt] = min(arr[cnt], i + j);
    //     }
    // }
    // for (int i = 1; i < 100; ++i) {
    //     cout << arr[i] << endl;
    // }
    Matrix A(2, 2);
    A.a = {{1, 1}, {1, 0}};
    A = Matrix::power(A, n + 2);
    cout << A.a[0][0] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}