#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 1e9 + 7;
int fast_pow(int base, int exp) {
    int result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                cnt++;
                x /= i;
            }
            factors.push_back({i, cnt});
        }
    }
    if (x > 1) {
        factors.push_back({x, 1});
    }
    return factors;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i], a[i]--;
    vector<int> vis(n, 0);
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        int path = 0;
        int cur = i;
        while (!vis[cur]) {
            // cout << cur + 1 << " -> ";
            vis[cur] = 1;
            cur = a[cur];
            path++;
        }
        // cout << endl;
        auto fact = factorize(path);
        for (auto [p, c] : fact) {
            freq[p] = max(freq[p], c);
        }
    }
    int ans = 1;
    for (auto [p, c] : freq) {
        ans = (ans * fast_pow(p, c)) % MOD;
    }
    cout << ans << endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
