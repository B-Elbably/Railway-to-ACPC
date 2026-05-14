#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 2e5 + 5;
int dp[N][2];
pair<int, int> val[N];
vector<int> adj[N];
int l,r;
int n;  

void dfs(int u, int p) {
    dp[u][0] = dp[u][1] = 0;
    for (int v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        int op1 = dp[v][0] + abs(val[u].first - val[v].first);
        int op2 = dp[v][1] + abs(val[u].first - val[v].second);
        dp[u][0] += max(op1, op2);

        op1 = dp[v][0] + abs(val[u].second - val[v].first);
        op2 = dp[v][1] + abs(val[u].second - val[v].second);
        dp[u][1] += max(op1, op2);
    }
}

void init() {
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i][1] = 0;
        adj[i].clear();
    }
}

void solve() {
    cin >> n;
    init();
    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        val[i] = {l, r};
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
