#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<pair<int, int>> adj[N]; 
bool visE[N];
vector<int> path;

void dfs(int u) {
    while (!adj[u].empty()) {
        auto [v, id] = adj[u].back();
        adj[u].pop_back();
        if (visE[id]) continue;
        visE[id] = true;
        dfs(v);
    }
    path.push_back(u);
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() & 1) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    dfs(1);
    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    reverse(path.begin(), path.end());
    for (int u : path) {
        cout << u << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}