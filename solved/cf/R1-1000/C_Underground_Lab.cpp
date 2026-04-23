#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 2e5 + 5;
vector<int> adj[N];
// int in[N], out[N];
vector<int> path;
int vis[N];

void dfs(int u) {
    vis[u] = 1;
    path.push_back(u);

    while (!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();
        if (vis[v]) continue;
        dfs(v);
        path.push_back(u);
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // out[u]++;
        // in[v]++;
    }

    // int start = -1, end = -1;
    // bool possible = true;

    // for (int i = 1; i <= n; i++) {
    //     if (out[i] == in[i]) continue;
    //     if (out[i] - in[i] == 1) {
    //         if (start != -1) possible = false;
    //         start = i;
    //     } else if (in[i] - out[i] == 1) {
    //         if (end != -1) possible = false;
    //         end = i;
    //     } else {
    //         possible = false;
    //     }
    // }

    // if (start == -1) {
    //     for (int i = 1; i <= n; i++) {
    //         if (out[i] > 0) {
    //             start = i;
    //             break;
    //         }
    //     }
    // }

    // if (start == -1 && m > 0) possible = false;

    // if (!possible) {
    //     cout << "IMPOSSIBLE" << endl;
    //     return;
    // }
    dfs(1);
    int sz = (2 * n + k - 1) / k;
    int idx = 0;
    for (int i = 0; i < k; i++) {
        int r = min(sz, (int)path.size() - idx);
        if (r <= 0) {
            cout << "1 1" << endl;
        } else {
            cout << r;
            for (int j = 0; j < r; j++) cout << " " << path[idx++];
            cout << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}