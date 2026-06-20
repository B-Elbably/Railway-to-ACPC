#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<pair<int, int>> facts;

void build() {
    vector<int> f;
    int now = 1;
    for (int i = 1; i <= 15; ++i) {
        now *= i;
        if (now > 1e12) break;
        f.push_back(now);
    }
    int k = f.size();
    for (int mask = 0; mask < (1 << k); ++mask) {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            if ((mask >> i) & 1) {
                sum += f[i];
            }
        }
        if (sum > 1e12) continue;
        facts.push_back({sum, __builtin_popcount(mask)});    
    }
}

void solve() {
    int n;
    cin >> n;
    int ans = __builtin_popcountll(n);
    for (auto& p : facts) {
        if (p.first <= n) {
            ans = min(ans, p.second + (int)__builtin_popcountll(n - p.first));
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}