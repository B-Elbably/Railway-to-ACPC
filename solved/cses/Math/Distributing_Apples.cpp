#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define nl '\n'

const int N = 3e6 + 5;
const int MOD = 1e9 + 7;

int fac[N], inv[N];

int power(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = (fac[i - 1] * i) % MOD;
    inv[N - 1] = power(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = (inv[i + 1] * (i + 1)) % MOD;
}

int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fac[n] * inv[n - r] % MOD;
}

// x1 + x2 + ... + xk = n
// LB: xi >= 0 (standard), UB: optional limit
int stars_and_bars(int n, int k) {
    if (n < 0 || k <= 0) return n == 0 && k == 0;
    return nCr(n + k - 1, k - 1);
}

// For xi >= ai: n_new = n - sum(ai)
int solve_lb(int n, int k, int ai) {
    return stars_and_bars(n - k * ai, k);
}

// Upper Bounds: xi <= bi (Uniform, using Inclusion-Exclusion)
// Logic: Total - (at least one xi > bi) + (at least two xi > bi) ...
int solve_ub(int n, int k, int bi) {
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        int ways = nCr(k, i) * stars_and_bars(n - i * (bi + 1), k) % MOD;
        if (i & 1) ans = (ans - ways + MOD) % MOD;
        else ans = (ans + ways) % MOD;
    }
    return ans;
}

int derangement(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    vector<int> D(n + 1);
    D[0] = 1; D[1] = 0;
    for (int i = 2; i <= n; i++) {
        D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % MOD;
    }
    return D[n];
}

int nCr_(int n, int r) { // O(r), if No MOD
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r;
    int res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    cout << solve_lb(k, n, 0) << nl; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}