#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int MOD = 1e9 + 7;

int fastpow(int n, int p) {
    int res = 1;
    n %= MOD;

    while (p) {
        if (p & 1)
            res = res * n % MOD;

        n = n * n % MOD;
        p >>= 1;
    }

    return res;
}

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    ans = (ans + fastpow(5, n)) % MOD;
    ans = (ans + fastpow(4, n)) % MOD;
    ans = (ans + fastpow(2, n)) % MOD;
    ans = (ans - 3 + MOD) % MOD;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}