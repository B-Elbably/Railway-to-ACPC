#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e6 + 5;
vector<int> divs[N];

void precompute() {
    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divs[j].push_back(i);
        }
    }
}

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int g = __gcd(x, y);
    x /= g; y /= g;
    unordered_map<int, int> memo;
    memo.reserve(1 << 15);
    auto go = [&](auto& go, int n) -> int {
        if (n == 1) return 0;
        if (n <= k) return 1;
        if (memo.count(n)) return memo[n];
        int res = 1e9;
        for (const int d : divs[n]) {
            if (d > k) break;
            res = min(res, 1 + go(go, n / d));
        }
        return memo[n] = res;
    };

    int ans = go(go, x);
    // memo.clear();
    ans += go(go, y);
    if (ans >= 1e9) ans = -1;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
