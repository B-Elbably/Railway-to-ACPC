#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, int delta) {
        for (i++; i <= n; i += i & -i) tree[i] += delta;
    }

    int query(int i) {
        int sum = 0;
        for (i++; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

struct Query {
    int l, r, id;
    bool operator<(const Query &other) const {
        return r < other.r;
    }
};

struct EulerTour {
    int n, timer;
    vector<int> tin, tout, tour;
    
    EulerTour(int n, const vector<long long>& vals, const vector<vector<int>>& adj) 
        : n(n), timer(0), tin(n + 1), tout(n + 1), tour(n) {
        dfs(1, 0, vals, adj);
    }

    void dfs(int u, int p, const vector<long long>& vals, const vector<vector<int>>& adj) {
        tin[u] = timer;
        tour[timer++] = vals[u];
        for (int v : adj[u]) {
            if (v != p) dfs(v, u, vals, adj);
        }
        tout[u] = timer;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<long long> vals(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) cin >> vals[i];
    vector<long long> b(vals.begin() + 1, vals.end());
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 1; i <= n; i++) {
        vals[i] = lower_bound(b.begin(), b.end(), vals[i]) - b.begin();
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    EulerTour et(n, vals, adj);
    vector<Query> queries(n);
    for (int i = 1; i <= n; ++i) {
        queries[i - 1] = {et.tin[i], et.tout[i] - 1, i};
    }
    sort(queries.begin(), queries.end());
    BIT bit(n);
    vector<int> pos(b.size(), -1);
    vector<int> ans(n + 1);
    int R = 0;

    for (const auto& q : queries) {
        while (R <= q.r) {
            int val = et.tour[R];
            if (~pos[val]) {
                bit.add(pos[val], -1);
            }
            bit.add(R, 1);
            pos[val] = R++;
        }
        ans[q.id] = bit.query(q.r) - bit.query(q.l - 1);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}