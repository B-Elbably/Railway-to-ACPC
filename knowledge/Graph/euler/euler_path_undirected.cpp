#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
bool vis[N];
vector<int> path;

void dfs(int u) {
    vis[u] = true;
    path.push_back(u);
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
            path.push_back(u);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int u: path) {
        cout << u << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}