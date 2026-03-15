#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define nl '\n'
const int N = 1e6 + 5;
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

void solve() {
    string s;
    cin >> s;
    map<char, int> freq;
    for (char c : s) freq[c]++;
    int ans = 1;
    for (auto& [c, f] : freq) {
        ans *= inv[f];
        ans %= MOD;
    }
    ans *= fac[s.size()];
    cout << ans % MOD << nl;
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