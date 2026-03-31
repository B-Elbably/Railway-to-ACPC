#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
string s;
const int N = 505;
const int MOD = 1e9 + 7;
int memo[N][N];

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


int go(int l, int r) {
    if ((r - l + 1) & 1) return 0;
    if (l > r) return 1;
    int &ret = memo[l][r];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = l + 1; i <= r; i += 2) {
        if (s[l] == s[i]) {
            int res = go(l + 1, i - 1) * go(i + 1, r);
            res %= MOD;
            ret += res * nCr((r - l + 1) / 2, (i - l + 1) / 2);
            ret %= MOD;
        }    
    }
    return ret;
}

void solve() {
    cin >> s;
    memset(memo, -1, sizeof memo);
    cout << go(0, s.length() - 1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
