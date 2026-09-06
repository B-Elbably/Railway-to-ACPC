#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 1e6 + 5;
int fact[N], inv[N];
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

void pre() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD;

    inv[N - 1] = mod_pow(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
}

int nCr(int n, int r) {
    if (r < 0 || r > n || n >= N) return 0;
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int generalized_catalan(int m, int open) {
    int k = (m + open) / 2;
    return (nCr(m, k) - nCr(m, k + 1) + MOD) % MOD;
}

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    if (n & 1) {
        cout << 0 << endl;
        return;
    }
    int open = 0;
    for (char c: s) {
        if (c == '(') open++;
        else open--;
        if (open < 0) {
            cout << 0 << endl;
            return;
        }
    }
    int m = n - s.length();
    if (open > m) {
        cout << 0 << endl;
        return;
    }
    if ((m + open) & 1) {
        cout << 0 << endl;
        return;
    }
    int k = (m + open) / 2;
    int ans = (nCr(m, k) - nCr(m, k + 1) + MOD) % MOD;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
