#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;

struct Matrix {
    int n, m;
    vector<vector<int>> a;

    Matrix(int n, int m, int val = 0) : n(n), m(m), a(n, vector<int>(m, val)) {}

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

    static Matrix power(Matrix base, int exp) {
        Matrix result = identity(base.n);
        while (exp > 0) {
            if (exp & 1) result = result * base;
            base = base * base;
            exp >>= 1;
        }
        return result;
    }
};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int modpow(int a, int b, int mod) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1)
            res = (__int128)res * a % mod;
        a = (__int128)a * a % mod;
        b >>= 1;
    }
    return res;
}

int extBSGS(int a, int b, int m) {
    a %= m;
    b %= m;
    if (b == 1 || m == 1) return 0;

    int g = __gcd(a, m);
    int count = 0;
    int na = 1;

    while (g > 1) {
        if (b % g != 0) {
            if (b == na) return count;
            return -1;
        }
        b /= g;
        m /= g;
        na = (__int128)na * (a / g) % m;
        count++;
        if (b == na) return count;
        g = __gcd(a, m);
    }

    int n = sqrtl(m) + 1;
    unordered_map<int, int, custom_hash> mp;
    mp.reserve(n * 2);
    
    int cur = b;
    for (int q = 0; q < n; q++) {
        mp[cur] = q;
        cur = (__int128)cur * a % m;
    }

    int an = modpow(a, n, m);
    cur = na;
    for (int p = 1; p <= n + 1; p++) {
        cur = (__int128)cur * an % m;
        if (mp.count(cur)) {
            return p * n - mp[cur] + count;
        }
    }
    return -1;
}

void solve() {
    int k, a, b;
    if (!(cin >> k >> a >> b)) return;

    int M = 0;
    if (k > 0) {
        Matrix A(2, 2);
        A.a = {{1, 1}, {1, 0}};

        Matrix base(2, 1);
        base.a = {{1}, {0}};

        Matrix res = Matrix::power(A, k - 1) * base;
        M = res.a[0][0];
    }

    if (M == 0) {
        if (b == 1) {
            cout << 0 << endl;
        } else if (b == 0) {
            if (a == 0) cout << 1 << endl;
            else cout << -1 << endl;
        } else {
            if (a == 0 || a == 1) {
                cout << -1 << endl;
            } else {
                int steps = 0;
                int current = 1;
                bool found = false;
                while (current <= b) {
                    if (current == b) {
                        cout << steps << endl;
                        found = true;
                        break;
                    }
                    if ((__int128)current * a > b) break;
                    current *= a;
                    steps++;
                }
                if (!found) cout << -1 << endl;
            }
        }
        return;
    }

    int ans = extBSGS(a, b, M);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}