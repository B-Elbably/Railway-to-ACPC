#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    long long lazy;
    bool has_lazy;
    Node(long long v = 0) : val(v), lazy(0), has_lazy(false) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        return Node(a.val + b.val);
    }

    void apply(int x, int lx, int rx, long long v) {
        seg[x].val = (rx - lx) - seg[x].val;
        seg[x].lazy = v;
        seg[x].has_lazy = !seg[x].has_lazy;
    }

    void push(int x, int lx, int rx) {
        if (!seg[x].has_lazy || rx - lx == 1) return;
        int mid = (lx + rx) >> 1;
        apply(2 * x + 1, lx, mid, seg[x].lazy);
        apply(2 * x + 2, mid, rx, seg[x].lazy);
        seg[x].lazy = 0;
        seg[x].has_lazy = false;
    }

    void build(const vector<long long> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size())
                seg[x] = Node(v[lx]);
            return;
        }

        int mid = (lx + rx) >> 1;
        build(v, 2 * x + 1, lx, mid);
        build(v, 2 * x + 2, mid, rx);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    void update(int x, int lx, int rx, int l, int r, long long v) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            apply(x, lx, rx, v);
            return;
        }

        push(x, lx, rx);
        int mid = (lx + rx) >> 1;
        update(2 * x + 1, lx, mid, l, r, v);
        update(2 * x + 2, mid, rx, l, r, v);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        if (lx >= r || rx <= l) return Node(0);
        if (lx >= l && rx <= r) return seg[x];

        push(x, lx, rx);
        int mid = (lx + rx) >> 1;
        return merge(
            query(2 * x + 1, lx, mid, l, r),
            query(2 * x + 2, mid, rx, l, r)
        );
    }

public:
    SegmentTree(const vector<long long> &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }

    void update(int l, int r, long long v) {
        update(0, 0, size, l, r, v);
    }

    long long query(int l, int r) {
        return query(0, 0, size, l, r).val;
    }
};

struct EulerTour {
    int n, timer;
    vector<int> tin, tout;
    vector<long long> tour;
    const vector<long long>& vals; 
    const vector<vector<int>>& adj;
    unique_ptr<SegmentTree> st;
    
    EulerTour(int n, const vector<long long>& v, const vector<vector<int>>& g, int root = 1) 
        : n(n), timer(0), tin(n + 1), tout(n + 1), tour(n), vals(v), adj(g) {
        
        dfs(root, 0);
        st = make_unique<SegmentTree>(tour);
    }

    void dfs(int u, int p) {
        tin[u] = timer;
        tour[timer++] = vals[u];
        for (int v : adj[u]) {
            if (v != p) dfs(v, u);
        }
        tout[u] = timer;
    }

    void update(int u, long long new_val) {
        st->update(tin[u], tout[u], new_val);
    }

    long long query(int u) {
        return st->query(tin[u], tout[u]);
    }
};

void solve() {
    int n, q;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int u; cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    vector<long long> vals(n + 1);
    for (int i = 1; i <= n; i++) cin >> vals[i];


    EulerTour et(n, vals, adj);
    cin >> q;
    while (q--) {
        string type; cin >> type;
        if (type == "pow") {
            int u;;
            cin >> u;
            et.update(u, 1);
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