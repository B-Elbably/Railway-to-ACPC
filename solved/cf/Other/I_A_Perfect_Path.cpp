#include <bits/stdc++.h>
using namespace std;


    #pragma GCC optimize("Ofast,unroll-loops")
    #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
     

vector<int> primes;
const int N = 2e5 + 1;
int spf[N];
const int sz = 17985;
unordered_map<int, int> idx;

void build() {
    iota(spf, spf + N, 0);
    for (int i = 2; i < N; i++) {
        if (spf[i] != i) continue;
        primes.push_back(i);
        idx[i] = primes.size() - 1;
        for (long long j = (long long) i * i; j < N; j += i) {
            if (spf[j] == j) spf[j] = i;
        }
    }
}

bitset<sz> factorize(int x) {
    bitset<sz> b;
    x = abs(x);
    while (x > 1) {
        int p = spf[x];
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt ^= 1;
        }
        if (cnt) b.flip(idx[p]);
    }
    return b;
}

struct Node {
    bitset<sz> mask;
    bool neg;
    int zero;
    Node(int x = 1, bool exit = false) {
        zero = (x == 0);
        if (exit) zero = -zero;
        neg = (x < 0);
        mask = factorize(abs(x));
    }
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;
    Node merge(const Node &a, const Node &b) { 
        Node res;
        res.mask = a.mask ^ b.mask;
        res.neg = a.neg ^ b.neg;
        res.zero = a.zero + b.zero;
        return res;
    }

    void build(const vector<Node> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size()) seg[x] = v[lx];
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
        if (lx >= r || rx <= l) return Node();
        if (lx >= l && rx <= r) return seg[x];
        int mid = (lx + rx) >> 1;
        return merge(query(2 * x + 1, lx, mid, l, r), query(2 * x + 2, mid, rx, l, r));
    }

public:
    SegmentTree(const vector<Node> &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }
    void update(int idx, long long v) { update(0, 0, size, idx, v); }
    Node query(int l, int r) { return query(0, 0, size, l, r); }
};

struct EulerTourPath {
    int n, timer, LOG;
    vector<int> tin, tout;
    vector<vector<int>> up;
    vector<Node> tour;
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
        tour[timer++] = Node(vals[u], 0);
        up[u][0] = p;
        for (int i = 1; i < LOG; i++) up[u][i] = up[up[u][i - 1]][i - 1];

        for (int v : adj[u]) {
            if (v != p) dfs(v, u);
        }

        tout[u] = timer;
        tour[timer++] = Node(vals[u], 1); 
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

    // void update(int u, long long new_val) {
    //     st->update(tin[u], new_val);
    //     st->update(tout[u], new_val);
    // }

    Node query_root(int u) {
        return st->query(0, tin[u] + 1);
    }

    Node query_path(int u, int v) {
        int l = get_lca(u, v);
        Node a = query_root(u);
        Node b = query_root(v);
        Node c = query_root(l);
        Node d = st->query(tin[l], tin[l] + 1);
        Node res;
        res.mask = a.mask ^ b.mask ^ d.mask;
        res.neg = a.neg ^ b.neg ^ d.neg;
        res.zero = a.zero + b.zero - 2 * c.zero + d.zero;
        return res;
    }
}; 

void solve() {
    int n, q;
    cin >> n;
    vector<long long> vals(n + 1);
    for (int i = 1; i <= n; i++) cin >> vals[i];
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    EulerTourPath et(n, vals, adj);
    cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        Node res = et.query_path(u, v);
        if (res.zero) {
            cout << "Yes\n";
        }else if (res.neg) {
            cout << "No\n";
        } else if (res.mask.count() == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    build();
    // cout << primes.size() << "\n";
    // sz = primes.size();
    // return 0;
    solve();
    return 0;
}