#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int MAXN = 1e6;
const int MOD = 1e9 + 7;
int fac[MAXN + 1];
int inv[MAXN + 1];
bool isPrime[MAXN + 1];

int modexp(int x, int n) {
    x %= MOD;
    int res = 1;
    while (n > 0) {
        if (n & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return res;
}

void factorial() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
}

void inverses() {
    inv[MAXN] = modexp(fac[MAXN], MOD - 2);
    for (int i = MAXN; i > 0; i--)
        inv[i - 1] = (inv[i] * i) % MOD;
}

int choose(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

void sieve() {
    fill(isPrime, isPrime + MAXN + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAXN; i++)
        if (isPrime[i])
            for (int j = i * i; j <= MAXN; j += i)
                isPrime[j] = false;
}

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int k = 2; k <= n; k++) {
        if (isPrime[k]) {
            ans += choose(n, k);
            ans %= MOD;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    factorial();
    inverses();
    sieve();

    int t;
    cin >> t;
    while (t--) solve();
}
