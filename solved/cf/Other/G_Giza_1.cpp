#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int modpow(int a, int x) {
    x %= MOD;
    int res = 1;
    while (x) {
        if (x & 1) res = (res * a) % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
}

int fac[N], inv[N];
void precompute() {
    fac[0] = 1;
    for (int i = 1; i < N; ++i) 
        fac[i] = fac[i - 1] * i % MOD;
    inv[N - 1] = modpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i) 
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

int nCr(int n, int r) {
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
} 
void solve() {
    int n, t;
    cin >> n >> t;
    cout << (nCr(n - 1, t) * 2 % MOD);
    // for (int i = 0; i <= n; ++i) {
    //     cout << (nCr(n, i) * 2) % MOD << " ";
    // }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    solve();
    return 0;
}
