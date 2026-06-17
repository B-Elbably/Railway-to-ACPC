#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 1e9 + 7;
const int inv2 = 500000004;

int sum(int x) {
    int p1 = x % MOD;
    int p2 = (x + 1) % MOD;
    return p1 * p2 % MOD * inv2 % MOD;
}

int range(int l, int r) {
    return (sum(r) - sum(l - 1) + MOD) % MOD;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int k = min(n, m);
    int ans = (n % MOD) * (k % MOD) % MOD;
    for (int l = 1; l <= k; ) {
        int q = n / l;
        int r = min(k, n / q);
        ans = (ans - (q % MOD) * range(l, r)) % MOD;
        l = r + 1;
    }
    if (m > n)
        ans = (ans + ((m - n) % MOD) * (n % MOD)) % MOD;

    cout << (ans + MOD) % MOD << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}