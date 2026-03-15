#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int fac[N], inv[N];

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
}

int nCr(int n, int r) {
    if (r < 0 || r > n || n >= N) return 0;
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int stars_and_bars(int n, int k) {
    if (n < 0 || k <= 0) return (n == 0 && k == 0);
    return nCr(n + k - 1, k - 1);
}

int distribute_with_lower_bound(int n, int k, int ai) {
    return stars_and_bars(n - k * ai, k);
}

int distribute_with_upper_bound(int n, int k, int bi) {
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        int ways = nCr(k, i) * stars_and_bars(n - i * (bi + 1), k) % MOD;
        if (i & 1) ans = (ans - ways + MOD) % MOD;
        else ans = (ans + ways) % MOD;
    }
    return ans;
}

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
