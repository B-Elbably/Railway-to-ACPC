#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 3e5 + 5;
vector<int> adj[N];
int ans[N];
int dp[N];
void dfs(int u, int p) {
    ans[u] = 1;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        ans[u] += ans[v];
    }
}
void dfs2(int u, int p) {
    int cnt = 0;
    vector<int> child;
    for (auto v : adj[u]) {
        if (v == p) continue;
        child.push_back(v);
        dfs2(v, u);
    }
    if (child.empty()){
        dp[u] = 0;
    } else if (child.size() == 1) {
        dp[u] = ans[child[0]] - 1;
    } else {
        int c1 = child[0], c2 = child[1];
        dp[u] = max(dp[c1] + ans[c2] - 1,
                    dp[c2] + ans[c1] - 1);
    }

};

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        ans[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    // for (int i = 1; i <= n; ++i) {
    //     sort(all(adj[i]), [&](int a, int b) {
    //         return ans[a] > ans[b];
    //     });
    // }
    dfs2(1, 0);
    cout << dp[1] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
