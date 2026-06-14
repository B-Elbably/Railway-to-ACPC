#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 2e5 + 5;
vector<int> adj[N];
int dep1[N], dep2[N], dep3[N];

void dfs(int u, int p, int d, int dep[]) {
    dep[u] = d;
    for (int v : adj[u]) {
        if (v != p) dfs(v, u, d + 1, dep);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0, 0, dep1);
    int u = max_element(dep1 + 1, dep1 + n + 1) - dep1;
    
    dfs(u, 0, 0, dep2);
    int v = max_element(dep2 + 1, dep2 + n + 1) - dep2;
    
    dfs(v, 0, 0, dep3);
    int w = 1, mx = -1;
    for (int i = 1; i <= n; ++i) {
        if (i == u) continue;
        if (i == v) continue;
        if (dep2[i] + dep3[i] > mx) {
            mx = dep2[i] + dep3[i];
            w = i;
        }
    }
    
    cout << (dep2[v] + dep2[w] + dep3[w]) / 2 << endl;
    cout << u << ' ' << v << ' ' << w << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}