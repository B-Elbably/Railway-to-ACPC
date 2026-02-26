#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 2e5 + 5;

int ans1[N], ans2[N];
vector<vector<int>> adj(N);

pair<int,int> bfs(int start, int dist[]) {
    queue<int> q;
    vector<int> vis(N, 0);
    q.push(start);
    vis[start] = 1;
    dist[start] = 0;
    int far = start;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        far = u;
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return {dist[far], far};
}

void solve() {
    int n; cin >> n;
    memset(ans1, 0, sizeof(ans1));
    memset(ans2, 0, sizeof(ans2));
    for (int i = 1; i < n; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto[_, u] = bfs(1, ans1);    
    auto[__, v] = bfs(u, ans1);  
    bfs(v, ans2);
    
    for (int i = 1; i <= n; i++) {
        cout << max(ans1[i], ans2[i]) << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}