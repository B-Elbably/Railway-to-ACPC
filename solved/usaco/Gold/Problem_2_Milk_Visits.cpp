#include <bits/stdc++.h>
using namespace std;

struct Node {
    unordered_map<int, int> freq;
    Node(long long v = 0) {
        if (v > 0) freq[v]++;
        else if (v < 0) freq[-v]--;
    }
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        Node result = a;
        for (auto const& [k, v] : b.freq) {
            result.freq[k] += v;
            if (result.freq[k] == 0) result.freq.erase(k);
        }
        return result;
    }

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

    int query(int x, int lx, int rx, int l, int r, int c) {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) {
            return seg[x].freq.count(c) ? seg[x].freq.at(c) : 0;
        }
        int mid = (lx + rx) >> 1;
        return query(2 * x + 1, lx, mid, l, r, c) + query(2 * x + 2, mid, rx, l, r, c);
    }

public:
    SegmentTree(const vector<long long> &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }
    
    int query(int l, int r, int c) { return query(0, 0, size, l, r, c); }
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

    int query_root(int u, int c) {
        return st->query(0, tin[u] + 1, c);
    }

    int query_path(int u, int v, int c) {
        int lca = get_lca(u, v);
        int lca_val = st->query(tin[lca], tin[lca] + 1, c);
        
        int root_u = query_root(u, c);
        int root_v = query_root(v, c);
        int root_lca = query_root(lca, c); 
        
        return root_u + root_v - 2 * root_lca + lca_val;
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
        int u, v, c;
        cin >> u >> v >> c;
        int count = et.query_path(u, v, c);
        cout << (count > 0 ? "1" : "0");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    solve();
}