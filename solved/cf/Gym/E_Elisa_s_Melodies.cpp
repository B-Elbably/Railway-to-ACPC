#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 1e9 + 7;

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, d, k, s;
    cin >> n >> d >> k >> s;
    int c = min(n, 2 * d + 1);   
    if (c == 1) {
        cout << k << "\n";
    } else {
        int num = (power(c, k) - 1 + MOD) % MOD;
        int den = power(c - 1, MOD - 2);
        cout << (num * den) % MOD << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
