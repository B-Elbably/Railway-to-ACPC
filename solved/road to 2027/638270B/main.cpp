#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int M = 1e6 + 5;
int spf[M];
void build() {
    for (int i = 1; i < M; ++i) spf[i] = i;
    for (int i = 2; i * i < M; ++i) {
        if (spf[i] == i) {
            for (int j = i; j < M; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}
const int N = 2e5 + 5;
vector<int> adj[N];
int ans[N];
set<int> coin[N];
void factorize(int u, int x) {
    while (x > 1) {
        int p = spf[x];
        coin[u].insert(p);
        while (x % p == 0) x /= p;
    }
    if (x > 1) coin[u].insert(x);
}

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (coin[u].size() < coin[v].size())
        swap(coin[u], coin[v]);
        for (int x : coin[v]) coin[u].insert(x);
        // coin[v].clear();
        ans[u] += ans[v];
    }
    ans[u] += coin[u].size() & 1;
    // ans[u] = ans[u] & 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        factorize(i, a[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    int res = 0;
    for (int i = 0; i < n; ++i) res += ans[i];
    cout << ans[0];
    // cout << res << endl;
    // for (int i = 0; i < n; ++i) cout << ans[i];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
