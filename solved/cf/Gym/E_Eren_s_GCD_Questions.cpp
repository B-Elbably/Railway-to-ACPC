#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int M = 1e7 + 5;
const int N = 1e3 + 5;
int spf[M];

void build() {
    for (int i = 0; i < M; i++) spf[i] = i;
    for (int i = 2; i < M; i++) {
        if (spf[i] != i) continue;
        for (int j = i * i; j < M; j += i) {
            if (spf[j] == j) spf[j] = i;
        }
    }
}

int ok[N][N];
vector<int> v;
const int LOG = 11;

vector<int> adj[N];
int up[N][LOG];
int d[N];
vector<int> primes[N];
int last[M];
int id = 0;

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        up[u][i] = up[ up[u][i - 1] ][i - 1];
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int lift(int u, int k) {
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            u = up[u][i];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    u = lift(u, d[u] - d[v]);
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

vector<int> factorize(int x) {
    vector<int> res;
    while (x > 1) {
        int p = spf[x];
        res.push_back(p);
        while (x % p == 0) x /= p;
    }
    return res;
}

bool check(int u, int v) {
    id++;
    auto process = [&](int x) {
        for (int p : primes[x]) {
            if (last[p] == id) return true;
            last[p] = id;
        }
        return false;
    };
    int w = lca(u, v);
    for (int x = u; x != w; x = up[x][0]) {
        if (process(x)) return true;
    }
    if (process(w)) return true;
    for (int x = v; x != w; x = up[x][0]) {
        if (process(x)) return true;
    }
    return false;
}

void solve() {
    int n; cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        primes[i] = factorize(v[i]);
    }
    for (int i = 1; i < n; ++i) {
        int u, b;
        cin >> u >> b;
        adj[u].push_back(b);
        adj[b].push_back(u);
    }
    dfs(1, 1);
    for (int u = 1; u <= n; u++) {
        for (int b = u; b <= n; b++) {
            ok[u][b] = ok[b][u] = check(u, b);
        }
    }
    int q; cin >> q;
    while (q--) { 
        int u, b; cin >> u >> b;
        cout << (ok[u][b] ? "YES" : "NO") << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t = 1;
    while (t--) solve();
    return 0;
}