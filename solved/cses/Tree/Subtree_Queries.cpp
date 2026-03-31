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

struct EulerTour {
    int n, timer;
    vector<int> tin, tout;
    vector<long long> flatten;
    const vector<long long>& vals; 
    const vector<vector<int>>& adj;
    unique_ptr<SegmentTree> st;
    
    EulerTour(int n, const vector<long long>& v, const vector<vector<int>>& g, int root = 1) 
        : n(n), timer(0), tin(n + 1), tout(n + 1), flatten(n), vals(v), adj(g) {
        
        dfs(root, 0);
        st = make_unique<SegmentTree>(flatten);
    }

    void dfs(int u, int p) {
        tin[u] = timer;
        flatten[timer++] = vals[u];
        for (int v : adj[u]) {
            if (v != p) dfs(v, u);
        }
        tout[u] = timer;
    }

    void update(int u, long long new_val) {
        st->update(tin[u], new_val);
    }

    long long query(int u) {
        return st->query(tin[u], tout[u]);
    }
};

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;
    
    vector<long long> vals(n + 1);
    for (int i = 1; i <= n; i++) cin >> vals[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    EulerTour et(n, vals, adj);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int u; long long x;
            cin >> u >> x;
            et.update(u, x);
        } else {
            int u; cin >> u;
            cout << et.query(u) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}