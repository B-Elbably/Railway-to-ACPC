#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
struct Edge {
    int x1, y1, x2, y2;
};
vector<Edge> ans;

int dfs(int u, int p, int &tail) {
    vector<int> endpoints;
    for (int v : adj[u]) {
        if (v == p) continue;
        int res = dfs(v, u, tail);
        if (~res) {
            if (endpoints.size() < 2) {
                endpoints.push_back(res);
            } else {
                ans.push_back({u, v, tail, res});
                tail = v; 
            }
        }
    }
    if (endpoints.empty()) return u; 
    if (endpoints.size() == 1) return endpoints[0];
    if (endpoints.size() == 2) {
        if (~p) {
            ans.push_back({u, p, tail, endpoints[0]});
            tail = endpoints[1];
        }
        return -1;
    }
    return -1;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) adj[i].clear();
    ans.clear();
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n == 2) {
        cout << "0\n";
        return;
    }
    int tail = -1;
    int root = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            root = i;
            break;
        }
    }

    tail = root;
    dfs(root, -1, tail);

    cout << ans.size() << "\n";
    for (auto &op : ans) {
        cout << op.x1 << " " << op.y1 << " " << op.x2 << " " << op.y2 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}