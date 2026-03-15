#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9 + 7;
const int N = 200005;

int fact[N], inv[N];

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % MOD;
    inv[N - 1] = power(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

int choose(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

void solve() {
    int n, m, k;
    cin >> n;
    m = 3; k = 2;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(all(a));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(all(a), a[i] + k) - a.begin() - 1;
        // ans += choose(j - i, m - 1);
        ans += (j - i) * (j - i - 1) / 2;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    while (t--) solve();
}
