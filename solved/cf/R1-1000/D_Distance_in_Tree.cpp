#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 5e4 + 5;
vector<int> adj[N];
int dep[N];
int n, k;
int dp[N][505];
int dp2[N];

void dfs(int u, int p) {
    dp[u][0] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int i = 0; i < k; i++) {
            dp2[u] += dp[u][i] * dp[v][k - i - 1];
        }
        for (int i = 1; i <= k; i++) {
            dp[u][i] += dp[v][i - 1];
        }
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << accumulate(dp2 + 1, dp2 + n + 1, 0LL) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
