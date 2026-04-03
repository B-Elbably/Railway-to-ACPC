#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    Node(long long v = 0) : val(v) {}
};

class MergeSortTree {
    int n;
    vector<vector<long long>> tree;

    void build(const vector<long long>& a, int node, int start, int end) {
        if (start == end) {
            tree[node].push_back(a[start]);
            return;
        }
        int mid = start + (end - start) / 2;
        build(a, 2 * node, start, mid);
        build(a, 2 * node + 1, mid + 1, end);
        
        merge(tree[2 * node].begin(), tree[2 * node].end(),
              tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
                back_inserter(tree[node]));
    }

    int query(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), val);
        }
        int mid = start + (end - start) / 2;
        return query(2 * node, start, mid, l, r, val) +
               query(2 * node + 1, mid + 1, end, l, r, val);
    }

public:
    MergeSortTree(const vector<long long>& a) {
        n = a.size();
        tree.resize(4 * n);
        if (n > 0) {
            build(a, 1, 0, n - 1);
        }
    }

    int query(int l, int r, long long val) {
        if (n == 0) return 0;
        return query(1, 0, n - 1, l, r, val);
    }
};

struct EulerTour {
    int n, timer;
    vector<int> tin, tout;
    vector<long long> tour;
    const vector<long long>& vals; 
    const vector<vector<int>>& adj;
    unique_ptr<MergeSortTree> st;
    
    EulerTour(int n, const vector<long long>& v, const vector<vector<int>>& g, int root = 1) 
        : n(n), timer(0), tin(n + 1), tout(n + 1), tour(n), vals(v), adj(g) {
        
        dfs(root, 0);
        st = make_unique<MergeSortTree>(tour);
    }

    void dfs(int u, int p) {
        tin[u] = timer;
        tour[timer++] = vals[u];
        for (int v : adj[u]) {
            if (v != p) dfs(v, u);
        }
        tout[u] = timer;
    }

    long long query(int u, long long val) {
        return st->query(tin[u], tout[u] - 1, val);
    }
};


void solve() {
    int n; cin >> n;
    vector<long long> vals(n + 1);
    for (int i = 1; i <= n; i++) cin >> vals[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int u; cin >> u;
        adj[u].push_back(i);
    }

    EulerTour et(n, vals, adj);

    for (int i = 1; i <= n; ++i) {
        cout << et.query(i, vals[i]) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("promote.in", "r", stdin);   
    freopen("promote.out", "w", stdout);
    solve();
    return 0;
}