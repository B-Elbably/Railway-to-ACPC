#include <bits/stdc++.h>
using namespace std;
 
const int N = 300001;
vector<int> adj[N];
int vis[N];
int mx = 0, fnode = 0;
 
void dfs(int u, int depth) {
    vis[u] = 1;
    if (depth > mx) {
        mx = depth;
        fnode = u;
    }
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v, depth + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    dfs(1, 0);
    memset(vis, 0, sizeof(vis));
    mx = 0;
    dfs(fnode, 0);
    cout << mx * 3 << '\n';
    return 0;
}