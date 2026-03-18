#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> dp(N, 0);   
    dp[0] = 1;
    for (int i : a) {
        for (int j = N - 1; j >= i; --j) {
            dp[j] |= dp[j - i];
        }
    }
    vector<int> ans;
    for (int i = 1; i < N; ++i) {
        if (dp[i]) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (int x: ans) cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
