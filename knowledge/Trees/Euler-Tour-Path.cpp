#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    Node(long long v = 0) : val(v) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;
    Node merge(const Node &a, const Node &b) { return Node(a.val + b.val); }

    void build(const vector<long long> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size()) seg[x] = Node(v[lx]);
            return;
        }
        int mid = (lx + rx) >> 1;
        build(v, 2 * x + 1, lx, mid);
        build(v, 2 * x + 2, mid, rx);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    void update(int x, int lx, int rx, int idx, long long v) {
        if (rx - lx == 1) {
            seg[x] = Node(v);
            return;
        }
        int mid = (lx + rx) >> 1;
        if (idx < mid) update(2 * x + 1, lx, mid, idx, v);
        else update(2 * x + 2, mid, rx, idx, v);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        if (lx >= r || rx <= l) return Node(0);
        if (lx >= l && rx <= r) return seg[x];
        int mid = (lx + rx) >> 1;
        return merge(query(2 * x + 1, lx, mid, l, r), query(2 * x + 2, mid, rx, l, r));
    }

public:
    SegmentTree(const vector<long long> &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }
    void update(int idx, long long v) { update(0, 0, size, idx, v); }
    long long query(int l, int r) { return query(0, 0, size, l, r).val; }
};

struct EulerTourPath {
    int n, timer, LOG;
    vector<int> tin, tout;
    vector<vector<int>> up;
    vector<long long> tour;
    const vector<long long>& vals;
    const vector<vector<int>>& adj;
    unique_ptr<SegmentTree> st;

    EulerTourPath(int n, const vector<long long>& v, const vector<vector<int>>& g, int root = 1) 
        : n(n), timer(0), tin(n + 1), tout(n + 1), tour(2 * n, 0), vals(v), adj(g) {
        
        LOG = 32 - __builtin_clz(n);
        up.assign(n + 1, vector<int>(LOG));
        dfs(root, root);
        st = make_unique<SegmentTree>(tour);
    }

    void dfs(int u, int p) {
        tin[u] = timer;
        tour[timer++] = vals[u]; 
        up[u][0] = p;
        for (int i = 1; i < LOG; i++) up[u][i] = up[up[u][i - 1]][i - 1];

        for (int v : adj[u]) {
            if (v != p) dfs(v, u);
        }

        tout[u] = timer;
        tour[timer++] = -vals[u]; 
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int get_lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = LOG - 1; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v)) u = up[u][i];
        }
        return up[u][0];
    }

    void update(int u, long long new_val) {
        st->update(tin[u], new_val);
        st->update(tout[u], -new_val);
    }

    long long query_root(int u) {
        return st->query(0, tin[u] + 1);
    }

    long long query_path(int u, int v) {
        int lca = get_lca(u, v);
        long long lca_val = st->query(tin[lca], tin[lca] + 1);
        return query_root(u) + query_root(v) - 2 * query_root(lca) + lca_val;
    }
};  

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> vals(n + 1);
    for (int i = 1; i <= n; i++) cin >> vals[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    EulerTourPath et(n, vals, adj);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int u; long long x;
            cin >> u >> x;
            et.update(u, x);
        } else {
            int u, v; cin >> u >> v;
            cout << et.query_path(u, v) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}