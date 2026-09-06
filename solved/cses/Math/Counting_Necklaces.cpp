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

void solve() {
    int n,m;
    cin >> n >> m;
    cout << count_necklaces(n, m) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
