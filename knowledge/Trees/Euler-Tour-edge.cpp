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

struct EulerTourEdge {
    int n, timer, LOG;
    vector<int> tin, tout;
    vector<vector<int>> up;
    vector<long long> tour;
    unique_ptr<SegmentTree> st;

    EulerTourEdge(int n, const vector<vector<pair<int, long long>>>& adj, int root = 3) 
        : n(n), timer(0), tin(n + 1), tout(n + 1), tour(2 * n, 0) {
        LOG = 32 - __builtin_clz(n);
        up.assign(n + 1, vector<int>(LOG));
        dfs(root, root, 0, adj);
        st = make_unique<SegmentTree>(tour);
    }

    void dfs(int u, int p, long long w, const vector<vector<pair<int, long long>>>& adj) {
        tin[u] = timer;
        tour[timer++] = w;
        up[u][0] = p;
        for (int i = 1; i < LOG; i++) up[u][i] = up[up[u][i - 1]][i - 1];
        for (auto& edge : adj[u]) {
            if (edge.first != p) dfs(edge.first, u, edge.second, adj);
        }
        tout[u] = timer;
        tour[timer++] = -w;
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

    void update(int u, long long val) {
        st->update(tin[u], val);
        st->update(tout[u], -val);
    }

    long long query_root(int u) {
        return st->query(0, tin[u] + 1);
    }

    long long query_path(int u, int v) {
        int lca = get_lca(u, v);
        return query_root(u) + query_root(v) - 2 * query_root(lca);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    EulerTourEdge et(n, adj, 3);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int u; long long w;
            cin >> u >> w;
            et.update(u, w);
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