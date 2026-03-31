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
    } else {
        for (int i = 0; i < order.size(); i++) {
            cout << order[i] << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}