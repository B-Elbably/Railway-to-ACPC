#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

// ==========================================
// CONFIGURATIONS & GLOBALS
// ==========================================
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int fac[N], inv[N], der[N];

// ==========================================
// 1. MODULAR ARITHMETIC
// ==========================================
int mod_pow(int base, int exp, int mod = MOD) {
    base %= mod;
    int res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// ==========================================
// 2. EXTENDED GCD & CRT
// ==========================================
int extgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

// Chinese Remainder Theorem: Returns {ok, value}. If no solution -> {false, 0}
pair<bool, int> crt(const vector<int>& a, const vector<int>& m) {
    int n = a.size();
    if (n == 0 || (int)m.size() != n) return {false, 0};

    int ans = a[0];
    int l = m[0];

    for (int i = 1; i < n; i++) {
        int x, y;
        int g = extgcd(l, m[i], x, y);
        int diff = a[i] - ans;

        if (diff % g != 0) return {false, 0};

        int step = m[i] / g;
        int mult = ((diff / g) % step) * (x % step) % step;
        if (mult < 0) mult += step;

        if (l != 0 && step > LLONG_MAX / l) return {false, 0};
        int mod = l * step;

        if (mult != 0 && l > LLONG_MAX / mult) return {false, 0};
        int add = l * mult;

        if (ans > LLONG_MAX - add) return {false, 0};
        ans = (ans + add) % mod;
        if (ans < 0) ans += mod;

        l = mod;
    }

    return {true, ans};
}

// ==========================================
// 3. COMBINATORICS PRECOMPUTATION & MODULO
// ==========================================
void precompute() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % MOD;

    inv[N - 1] = mod_pow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;

    der[0] = 1;
    der[1] = 0;
    for (int i = 2; i < N; i++) der[i] = (i - 1) * ((der[i - 1] + der[i - 2]) % MOD) % MOD;
}

// Combination nCr in O(1)
int nCr(int n, int r) {
    if (r < 0 || r > n || n >= N) return 0;
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

// Combination nCr in O(r) - useful when n is very large but r is small
int nCr2(int n, int r) {
    if (r < 0 || r > n) return 0;
    int num = 1;
    for (int i = 0; i < r; i++) {
        num = num * ((n - i) % MOD) % MOD;
    }
    return num * inv[r] % MOD;
}

// Permutation nPr in O(1)
int nPr(int n, int r) {
    if (r < 0 || r > n || n >= N) return 0;
    return fac[n] * inv[n - r] % MOD;
}

// Catalan number C_n in O(1)
int catalan(int n) {
    if (n < 0 || 2 * n >= N) return 0;
    return nCr(2 * n, n) * mod_pow(n + 1, MOD - 2) % MOD;
}

// Derangement D_n in O(1)
int derangement(int n) {
    if (n < 0 || n >= N) return 0;
    return der[n];
}

// Stirling numbers of the second kind S(n, k) in O(k log n)
int stirling2(int n, int k) {
    if (n < k || k < 0 || k >= N) return 0;
    if (n == k) return 1;
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        int ways = nCr(k, i) * mod_pow(i, n) % MOD;
        if ((k - i) & 1) ans = (ans - ways + MOD) % MOD;
        else ans = (ans + ways) % MOD;
    }
    return ans * inv[k] % MOD;
}

// ==========================================
// 4. DISTRIBUTION & STARS AND BARS
// ==========================================
// Distribute n identical items into k distinct bins in O(1)
int stars_and_bars(int n, int k) {
    if (n < 0 || k <= 0) return (n == 0 && k == 0);
    return nCr(n + k - 1, k - 1);
}

// Distribute n identical items into k distinct bins with each bin >= ai in O(1)
int distribute_with_lower_bound(int n, int k, int ai) {
    return stars_and_bars(n - k * ai, k);
}

// Distribute n identical items into k distinct bins with each bin <= bi in O(k)
int distribute_with_upper_bound(int n, int k, int bi) {
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        int ways = nCr(k, i) * stars_and_bars(n - i * (bi + 1), k) % MOD;
        if (i & 1) ans = (ans - ways + MOD) % MOD;
        else ans = (ans + ways) % MOD;
    }
    return ans;
}

// ==========================================
// 5. BURNSIDE'S LEMMA & NECKLACES / BRACELETS
// ==========================================
// Distinct necklaces of length n with m colors under rotation in O(n log n)
int count_necklaces(int n, int m) {
    if (n == 0) return 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum + mod_pow(m, gcd(i, n))) % MOD;
    }
    return sum * mod_pow(n, MOD - 2) % MOD;
}

// Distinct bracelets of length n with m colors under rotation and reflection in O(n log n)
int count_bracelets(int n, int m) {
    if (n == 0) return 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum = (sum + mod_pow(m, gcd(i, n))) % MOD;
    }

    if (n & 1) {
        sum = (sum + n % MOD * mod_pow(m, (n + 1) / 2) % MOD) % MOD;
    } else {
        sum = (sum + (n / 2) % MOD * mod_pow(m, n / 2) % MOD) % MOD;
        sum = (sum + (n / 2) % MOD * mod_pow(m, n / 2 + 1) % MOD) % MOD;
    }

    return sum * mod_pow(2 * n % MOD, MOD - 2) % MOD;
}

// ==========================================
// 6. EXACT & GENERAL COUNTING TOOLS
// ==========================================
// Exact nCr without modulo. Returns -1 if it overflows long long.
int nCr_exact(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r;

    vector<int> denom(r);
    for (int i = 0; i < r; i++) denom[i] = i + 1;

    int res = 1;
    for (int num = n - r + 1; num <= n; num++) {
        int cur = num;
        for (int j = 0; j < r && cur > 1; j++) {
            int g = gcd(cur, denom[j]);
            if (g > 1) {
                cur /= g;
                denom[j] /= g;
            }
        }
        if (cur > 1 && res > LLONG_MAX / cur) return -1;
        res *= cur;
    }
    return res;
}

// Count numbers in [1..limit] divisible by at least one divisor using inclusion-exclusion
int inclusion_exclusion_multiples(const vector<int>& divisors, int limit) {
    int m = divisors.size();
    int ans = 0;

    for (int mask = 1; mask < (1 << m); mask++) {
        int l = 1;
        bool bad = false;

        for (int i = 0; i < m; i++) {
            if ((mask >> i) & 1) {
                int g = gcd(l, divisors[i]);
                int left = l / g;
                if (divisors[i] != 0 && left > limit / divisors[i]) {
                    bad = true;
                    break;
                }
                l = left * divisors[i];
            }
        }

        if (bad || l == 0) continue;
        if (__builtin_popcount(mask) & 1) ans += limit / l;
        else ans -= limit / l;
    }

    return ans;
}

void solve() {
    // Write your code here
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
