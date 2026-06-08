#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 200005;
vector<int> adj[N];
int deg[N];
vector<int> order;

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        deg[i] = 0;
    }
    order.clear();

    for (int i = 0; i < m; i++) {
        int type; cin >> type;
        int u, v;
        cin >> u >> v;
        if (type == 2) {
            swap(u, v);
        }
        adj[u].push_back(v);
        deg[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) pq.push(i);
    }

    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (--deg[v] == 0)
                pq.push(v);
        }
    }

    if (order.size() < n) {
        cout << "Zeyad Can't Study\n";
    } else {
        for (int x : order) cout << x << " ";
        cout << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}