#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 2e5 + 5;
vector<int> vis;
map<int, set<int>> adj;

void dfs(int u) {
    vis[u] = true;
    for (auto v : adj[u]) 
        if (!vis[v]) dfs(v);
}

void solve() {
    int n; cin >> n;
    vis.assign(n + 1, false);
    adj.clear();
    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        adj[x].insert(i);
        adj[i].insert(x);
        deg[i] = adj[i].size(); deg[x] = adj[x].size();
    }

    int cycles = 0, notCycle = 0;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1 && !vis[i]) {
            dfs(i);
            notCycle++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
            cycles++;
        }
    }
    cout << cycles + (notCycle != 0) << " " << cycles + notCycle << endl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
