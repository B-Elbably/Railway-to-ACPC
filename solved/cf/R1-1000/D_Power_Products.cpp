#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n, k;
vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                cnt++;
                x /= i;
            }
            cnt %= k;
            if (cnt) factors.push_back({i, cnt});
        }
    }
    if (x > 1) {
        factors.push_back({x, 1});
    }
    return factors;
}

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    map<vector<pair<int, int>>, int> freq;
    int ones = 0;
    for (int i : a) {
        auto now = factorize(i);
        if (now.empty()) {
            ones++;
        } else {
            freq[now]++;
        }
    }

    int ans = 0;
    for (int i : a) {
        auto now = factorize(i);
        if (now.empty()) {
            ones--;
            ans += ones;
        } else {
            freq[now]--;
            vector<pair<int, int>> target;
            for (auto [p, c] : now) {
                target.push_back({p, k - c});
            }
            ans += freq[target];
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}