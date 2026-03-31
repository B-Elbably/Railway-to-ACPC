#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int M = 1e9 + 7;
int exp(int base, int exp) {
    int res = 1; 
    base %= M;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % M;
        base = (base * base) % M; 
        exp /= 2;
    }
    return res;
}

vector<pair<int, int>> prime_factors(int n) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            factors.emplace_back(i, count);
        }
    }
    if (n > 1) factors.emplace_back(n, 1);
    return factors;
}

void solve() {
    int a, b;
    cin >> a >> b;
    b %= M - 1;
    // -> (p^(e+1) - 1) / (p - 1)
    auto factors = prime_factors(a);
    int ans = 1;
    for (auto& [p, e] : factors) {
        e *= b;
        int term = (exp(p, e + 1) - 1 + M) % M;
        term = (term * exp(p - 1, M - 2)) % M;
        ans = (ans * term) % M;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("sumdiv.in", "r", stdin);
    // freopen("sumdiv.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
