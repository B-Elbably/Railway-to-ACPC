#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

// Exact nCr without modulo. Returns -1 if it overflows long long.
int nCr_exact(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r;

    vector<int> denom(r);
    for (int i = 0; i < r; i++) denom[i] = i + 1;

    int res = 1;
    for (int num = n - r + 1; num <= n; num++) {
        int cur = num;
        for (int j = 0; j < r && cur > 1; j++) {
            int g = gcd(cur, denom[j]);
            if (g > 1) {
                cur /= g;
                denom[j] /= g;
            }
        }
        if (cur > 1 && res > LLONG_MAX / cur) return -1;
        res *= cur;
    }
    return res;
}

// Count numbers in [1..limit] divisible by at least one divisor.
int inclusion_exclusion_multiples(const vector<int>& divisors, int limit) {
    int m = divisors.size();
    int ans = 0;

    for (int mask = 1; mask < (1 << m); mask++) {
        int l = 1;
        bool bad = false;

        for (int i = 0; i < m; i++) {
            if ((mask >> i) & 1) {
                int g = gcd(l, divisors[i]);
                int left = l / g;
                if (divisors[i] != 0 && left > limit / divisors[i]) {
                    bad = true;
                    break;
                }
                l = left * divisors[i];
            }
        }

        if (bad || l == 0) continue;
        if (__builtin_popcount(mask) & 1) ans += limit / l;
        else ans -= limit / l;
    }

    return ans;
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
