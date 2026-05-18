#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 2e5 + 5;
vector<int> adj[N];
int sz[N], dep[N], par[N];
int ans[N];
int sum = 0;
void dfs(int u, int p, int d) {
    sz[u] = 1;
    dep[u] = d;
    par[u] = p;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
        sz[u] += sz[v];
    }
    sum += sz[u];
}
int n;
void dfs2(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        ans[v] = ans[u] + n - 2 * sz[v];
        dfs2(v, u);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    ans[1] = sum;
    // cout << sum << endl;
    dfs2(1, 0);
    cout << *max_element(ans + 1, ans + n + 1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
