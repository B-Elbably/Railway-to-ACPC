#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 2e6 + 5;
const int MOD = 1e9 + 7;

int fac[N], inv[N], der[N];

int power(int base, int exp) {
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

    inv[N - 1] = power(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;

    der[0] = 1;
    der[1] = 0;
    for (int i = 2; i < N; i++) der[i] = (i - 1) * ((der[i - 1] + der[i - 2]) % MOD) % MOD;
}

int nCr(int n, int r) {
    if (r < 0 || r > n || n >= N) return 0;
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}


void solve() {
    int k; string s;
    cin >> k >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        int ways = nCr(n + i - 1, i);
        ways *= power(26, k - i); ways %= MOD;
        ways *= power(25, i); ways %= MOD;
        ans += ways; ans %= MOD;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
