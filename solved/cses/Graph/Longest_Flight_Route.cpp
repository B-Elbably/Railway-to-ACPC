#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 200005;
vector<int> adj[N];
int deg[N];
vector<int> order;

int memo[N], p[N]; 
void solve() {
    int n, m;
    cin >> n >> m;
    memset(memo, -1, sizeof(memo));
    memset(p, -1, sizeof(p));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq; 
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) pq.push(i);
    }

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            deg[v]--;
            if (deg[v] == 0) pq.push(v);
        }
    }

    if (order.size() < n) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    memo[1] = 1;
    for (int u : order) {
        if (memo[u] == -1) continue;
        for (int v : adj[u]) {
            if (memo[u] + 1 > memo[v]) {
                memo[v] = memo[u] + 1;
                p[v] = u;
            }
        }
    }

    if (memo[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> path;
    for (int u = n; u != -1; u = p[u]) {
        path.push_back(u);
    }
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (int x : path) cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}