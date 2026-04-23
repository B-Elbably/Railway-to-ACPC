#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 2e5 + 5;
vector<int> adj[N];
int in[N], out[N];
vector<int> path;

void dfs(int u) {
    while (!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();
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
        adj[u].push_back(v);
        out[u]++; in[v]++;
    }

    int start = -1, end = -1;
    bool ok = true;

    for (int i = 1; i <= n; i++) {
        if (out[i] == in[i]) continue;
        if (out[i] - in[i] == 1) {
            if (start != -1) ok = false;
            start = i;
        } else if (in[i] - out[i] == 1) {
            if (end != -1) ok = false;
            end = i;
        } else {
            ok = false;
        }
    }

    if (start == -1) {
        for (int i = 1; i <= n; i++) {
            if (out[i] > 0) {
                start = i;
                break;
            }
        }
    }
    for (int i = 2; i < n; ++i) {
        if (in[i] != out[i]) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    if (in[n] - out[n] != 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    dfs(1);
    
    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    reverse(path.begin(), path.end());
    if (path.back() != n ) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (int u : path) {
        cout << u << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}