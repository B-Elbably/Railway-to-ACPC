#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int ans;
const int N = 2e5 + 5;
vector<int> adj[N];
set<int> st[N];
int dp[N];

void dfs(int u, int p) {
    dp[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] += dp[v] + st[v].count(u);
    }
}

void reroot(int u, int p) {
    ans = min(ans, dp[u]);
    for (int v : adj[u]) {
        if (v == p) continue;
        int ui = dp[u];
        dp[u] -= dp[v] + st[v].count(u);
        dp[v] += dp[u] + st[u].count(v);
        reroot(v, u);
        dp[u] = ui;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        st[u].insert(v);
    }
    dfs(1, 0);
    ans = 1e18;
    reroot(1, 0);
    vector<int> res;

    cout << ans << endl;
    for (int x = 1; x <= n; x++)   
        if (dp[x] == ans)
            cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
