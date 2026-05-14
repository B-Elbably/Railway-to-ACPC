#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 1e6 + 5;
const int MOD = 998244353;

int fac[N], inv[N], der[N];

int mod_pow(int base, int exp) {
    base %= MOD;
    int res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % MOD;

    inv[N - 1] = mod_pow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;

    der[0] = 1;
    der[1] = 0;
    for (int i = 2; i < N; i++) der[i] = (i - 1) * ((der[i - 1] + der[i - 2]) % MOD) % MOD;
}

int nCr(int n, int r) {
    if (r < 0 || r > n || n >= N) return 0;
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int nPr(int n, int r) {
    if (r < 0 || r > n || n >= N) return 0;
    return fac[n] * inv[n - r] % MOD;
}

int catalan(int n) {
    if (n < 0 || 2 * n >= N) return 0;
    return nCr(2 * n, n) * mod_pow(n + 1, MOD - 2) % MOD;
}

int derangement(int n) {
    if (n < 0 || n >= N) return 0;
    return der[n];
}

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

int nCr2(int n, int r) {
    if (r < 0 || r > n) return 0;
    int num = 1;
    r = min(r, n - r);
    for (int i = 0; i < r; i++) {
        num = num * ((n - i) % MOD) % MOD;
    }
    return num * inv[r] % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n - k + 1);
    for (auto &x : b) cin >> x;
    vector<int> mn(k, 0);
    for (int r = 0; r < k; r++) {
        int cur = 0;
        for (int i = r; i < n - k; i += k) {
            cur += b[i + 1] - b[i];
            mn[r] = min(mn[r], cur);
        }
    }
    int sum = b[0] + accumulate(all(mn), 0LL);
    cout << nCr2(sum + k - 1, k - 1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
