#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;

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

int count_necklaces(int n, int m) {
    if (n == 0) return 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum + mod_pow(m, gcd(i, n))) % MOD;
    }
    return sum * mod_pow(n, MOD - 2) % MOD;
}

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

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
