#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 512;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> dp(N, 1e18);
    dp[0] = 0;
    for (int x : a) {
        for (int j = 0; j < N; j++) {
            if (dp[j] < x) {
                dp[j ^ x] = min(dp[j ^ x], x);
            }
        }
    }
    vector<int> res;
    for (int i = 0; i < N; i++) {
        if (dp[i] != 1e18) {
            res.push_back(i);
        }
    }

    cout << res.size() << endl;
    for (int x : res) {
        cout << x << ' ';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}