#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;
int n;
int a[N];
int dp[N][2];
bool vis[N][2];

int solve_dp(int i, int parity) {
    if (i == n) return 0;

    if (vis[i][parity]) return dp[i][parity];
    vis[i][parity] = true;

    int res = 0;

    if (parity == 1) {
        // odd → can take or skip
        res = max({
            solve_dp(i + 1, 1),                 // skip
            a[i] + solve_dp(i + 1, 0)           // take
        });
    } else {
        // even → must skip
        res = solve_dp(i + 1, 1);
    }

    return dp[i][parity] = res;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            vis[i][0] = vis[i][1] = false;
        }

        cout << solve_dp(0, 1) << endl; // start at position 1 (odd)
    }
}