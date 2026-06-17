#include <bits/stdc++.h>
using namespace std;

// Mo's Algorithm on Trees (Path Queries)
// Time Complexity: O((N + Q) * sqrt(N) * Cost(add/remove))
// Space Complexity: O(N * log(N) + Q)

struct MoTree {
    struct Query {
        int l, r, id, block;
        int lca; // LCA of the query nodes, if it needs to be added manually (LCA != u)
        
        bool operator<(const Query& other) const {
            if (block != other.block)
                return block < other.block;
            return (block & 1) ? (r < other.r) : (r > other.r);
        }
    };

    int n;
    int timer;
    vector<vector<int>> adj;
    vector<int> tin, tout, depth;
    vector<vector<int>> up; // binary lifting table for LCA
    vector<int> euler;
    int lg;

    int block_size;
    vector<Query> queries;

    MoTree(int n) : n(n), timer(0), adj(n), tin(n), tout(n), depth(n) {
        lg = __lg(n) + 1;
        up.assign(n, vector<int>(lg + 1));
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p = 0, int d = 0) {
        tin[u] = timer;
        euler.push_back(u);
        timer++;
        
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i <= lg; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
            }
        }

        tout[u] = timer;
        euler.push_back(u);
        timer++;
    }

    void init(int root = 0) {
        dfs(root, root, 0);
        block_size = max(1, (int)((2 * n) / sqrt(max(1, (int)queries.size()))));
        for (auto& qry : queries) {
            qry.block = qry.l / block_size;
        }
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = lg; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = lg; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    void add_query(int u, int v, int id) {
        if (tin[u] > tin[v]) swap(u, v);
        int lca = get_lca(u, v);
        
        if (lca == u) {
            // Case 1: u is an ancestor of v
            // Range: [tin[u], tin[v]]
            queries.push_back({tin[u], tin[v], id, 0, -1});
        } else {
            // Case 2: u and v are on different branches
            // Range: [tout[u], tin[v]] and we need to manually add LCA
            queries.push_back({tout[u], tin[v], id, 0, lca});
        }
    }

    vector<int> solve(const vector<int>& values) {
        int q = queries.size();
        vector<int> ans(q);

        sort(queries.begin(), queries.end());

        // --- Custom State Variables ---
        int current_ans = 0;
        
        // Example: Counting number of distinct values on the path
        int max_val = 0;
        if (!values.empty()) max_val = *max_element(values.begin(), values.end());
        vector<int> freq(max_val + 1, 0);
        vector<bool> active(n, false);

        auto add_node = [&](int u) {
            int val = values[u];
            if (freq[val] == 0) {
                current_ans++;
            }
            freq[val]++;
        };

        auto remove_node = [&](int u) {
            int val = values[u];
            freq[val]--;
            if (freq[val] == 0) {
                current_ans--;
            }
        };

        // Toggle node u's presence in the current path set
        auto toggle = [&](int u) {
            if (active[u]) {
                remove_node(u);
            } else {
                add_node(u);
            }
            active[u] = !active[u];
        };
        // ------------------------------

        int cur_l = 0, cur_r = -1;

        for (const auto& qry : queries) {
            // Expand range
            while (cur_l > qry.l) {
                cur_l--;
                toggle(euler[cur_l]);
            }
            while (cur_r < qry.r) {
                cur_r++;
                toggle(euler[cur_r]);
            }
            // Shrink range
            while (cur_l < qry.l) {
                toggle(euler[cur_l]);
                cur_l++;
            }
            while (cur_r > qry.r) {
                toggle(euler[cur_r]);
                cur_r--;
            }

            // If query LCA is valid (Case 2), toggle LCA, record answer, then untoggle LCA
            if (qry.lca != -1) {
                toggle(qry.lca);
            }
            
            ans[qry.id] = current_ans;

            if (qry.lca != -1) {
                toggle(qry.lca);
            }
        }
        return ans;
    }
};

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    MoTree solver(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        solver.add_edge(u - 1, v - 1);
    }

    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        solver.add_query(u - 1, v - 1, i);
    }

    // Call init to build the Euler tour, depths, and LCA up table
    solver.init(0);

    vector<int> ans = solver.solve(values);
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; // uncomment if multi-testcase
    while (t--) {
        solve();
    }
    return 0;
}
