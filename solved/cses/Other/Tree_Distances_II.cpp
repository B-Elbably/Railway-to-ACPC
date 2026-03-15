#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 2e5 + 5;
int children[N], ans[N];
vector<int> adj[N];

void dfs(int u, int p = -1) {
    children[u] = 1;
    for (int v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        children[u] += children[v];
    }
} 

int total = 0;
void dfs2(int u, int p = -1, int depth = 0) {
    total += depth;
    for (int v: adj[u]) {
        if (v == p) continue;
        dfs2(v, u, depth + 1);
    }
}

int n;
void dfs3(int u, int p = -1) {
    for (int v: adj[u]) {
        if (v == p) continue;
        ans[v] = ans[u] + (n - 2 * children[v]);
        dfs3(v, u);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    dfs2(1);
    ans[1] = total;
    dfs3(1);
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
