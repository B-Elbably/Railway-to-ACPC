#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 5e2 + 5;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    vector<vector<int>> dp(N, vector<int>(N, 0));
    dp[0][0] = 1;

    for (int c : a) {
        for (int i = x; i >= c; --i) {
            for (int j = i; j >= 0; --j) {
                dp[i][j] |= dp[i - c][j]; // not take c
                if (j >= c) {
                    dp[i][j] |= dp[i - c][j - c]; // take c
                }
            }
        }
    }
    
    vector<int> ans;
    for (int i = 0; i <= x; ++i) {
        if (dp[x][i]) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (int val : ans) cout << val << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}