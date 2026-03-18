#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e3 + 5;
const int INF = 1e15;
vector<int> adj[N];
int a[N];
int n, m, c;
int memo[N][1005];

int dfs(int u, int t) {
    if (t == 0) return u == 1 ? 0 : -INF;
    if (~memo[u][t]) return memo[u][t];
    int res = -INF;
    for (int v : adj[u]) {
        res = max(res, a[v] + dfs(v, t - 1));
    }
    return memo[u][t] = res;
}

void solve() {
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    memset(memo, -1, sizeof(memo));
    int ans = 0;
    for (int t = 1; t <= 1000; t++) {
        int val = dfs(1, t) - c * t * t;
        ans = max(ans, val );
    }
    
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    int t = 1;
    while (t--) solve();
}