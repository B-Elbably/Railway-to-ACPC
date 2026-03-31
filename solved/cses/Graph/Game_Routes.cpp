#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 200005;
vector<int> adj[N];
int deg[N], ans[N];
const int MOD = 1e9 + 7;
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    int res = 0;
    priority_queue<int, vector<int>, greater<int>> pq; 
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            pq.push(i);
        }
    }
    ans[1] = 1;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        for (int v : adj[u]) {
            ans[v] = (ans[v] + ans[u]) % MOD;
            deg[v]--;
            if (deg[v] == 0) pq.push(v);
        }
    }
    cout << ans[n] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}