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

    EulerTourEdge(int n, const vector<vector<pair<int, long long>>>& adj, int root = 1)
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

int vis[100005];
vector<vector<pair<int, long long>>> graph_adj;
vector<vector<pair<int, long long>>> adj;
vector<int> bad_nodes;

void dfs(int u, int p = 0) {
    vis[u] = 1;
    for (auto &e : graph_adj[u]) {
        int v = e.first;
        long long w = e.second;
        if (v == p) continue;
        if (!vis[v]) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            dfs(v, u);
        } else if (u < v) {
            bad_nodes.push_back(u);
            bad_nodes.push_back(v);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    graph_adj.resize(n + 1);
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; long long w;
        cin >> u >> v >> w;
        graph_adj[u].push_back({v, w});
        graph_adj[v].push_back({u, w});
    }

    dfs(1);
    sort(bad_nodes.begin(), bad_nodes.end());
    bad_nodes.erase(unique(bad_nodes.begin(), bad_nodes.end()), bad_nodes.end());
    int k = bad_nodes.size();
    vector<vector<long long>> dist(k, vector<long long>(n + 1, 1e18));
    for (int i = 0; i < k; i++) {
        int start = bad_nodes[i];
        dist[i][start] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, start});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[i][u]) continue;
            for (auto &e : graph_adj[u]) {
                int v = e.first;
                long long w = e.second;
                if (dist[i][v] > d + w) {
                    dist[i][v] = d + w;
                    pq.push({dist[i][v], v});
                }
            }
        }
    }

    int q; cin >> q;
    EulerTourEdge et(n, adj, 1);

    while (q--) {
        int u, v; cin >> u >> v;
        long long ans = et.query_path(u, v);
        for (int i = 0; i < k; i++) {
            ans = min(ans, dist[i][u] + dist[i][v]);
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}