#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

vector<int> adj[200001];
int ans[200001];
void dfs(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        ans[u] +=  1 + ans[v];
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
