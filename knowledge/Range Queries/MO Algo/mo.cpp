#include <bits/stdc++.h>
using namespace std;

// Mo's Algorithm (Offline Range Queries)
// Time Complexity: O((N + Q) * sqrt(N) * Cost(add/remove))
// Space Complexity: O(N + Q)

struct Mo {
    struct Query {
        int l, r, id, block;
        // Alternating sorting: odd blocks sort r ascending, even blocks sort r descending.
        // This reduces the right pointer (r) movement.
        bool operator<(const Query& other) const {
            if (block != other.block)
                return block < other.block;
            return (block & 1) ? (r < other.r) : (r > other.r);
        }
    };

    int n;
    int block_size;
    vector<Query> queries;

    Mo(int n) : n(n), block_size(320) {}

    void add_query(int l, int r, int id) {
        queries.push_back({l, r, id, 0});
    }

    // Dynamic block size optimization: block_size = N / sqrt(Q)
    void calculate_block_size() {
        int q = queries.size();
        block_size = max(1, (int)(n / sqrt(max(1, q))));
        for (auto& qry : queries) {
            qry.block = qry.l / block_size;
        }
    }

    vector<int> solve(const vector<int>& a) {
        int q = queries.size();
        vector<int> ans(q);
        
        calculate_block_size();
        sort(queries.begin(), queries.end());

        // --- Custom State Variables ---
        int current_ans = 0;
        
        // Example: Counting number of distinct elements
        // Frequency array: adjust size depending on max element value
        int max_val = 0;
        if (!a.empty()) max_val = *max_element(a.begin(), a.end());
        vector<int> freq(max_val + 1, 0);

        auto add = [&](int idx) {
            int val = a[idx];
            if (freq[val] == 0) {
                current_ans++;
            }
            freq[val]++;
        };

        auto remove = [&](int idx) {
            int val = a[idx];
            freq[val]--;
            if (freq[val] == 0) {
                current_ans--;
            }
        };
        // ------------------------------

        int cur_l = 0, cur_r = -1;

        for (const auto& qry : queries) {
            // Expand range
            while (cur_l > qry.l) {
                cur_l--;
                add(cur_l);
            }
            while (cur_r < qry.r) {
                cur_r++;
                add(cur_r);
            }
            // Shrink range
            while (cur_l < qry.l) {
                remove(cur_l);
                cur_l++;
            }
            while (cur_r > qry.r) {
                remove(cur_r);
                cur_r--;
            }
            ans[qry.id] = current_ans;
        }
        return ans;
    }
};

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Mo solver(n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        // Adjust for 0-indexed or 1-indexed input queries
        // Example assuming 1-indexed queries:
        solver.add_query(l - 1, r - 1, i);
    }

    vector<int> ans = solver.solve(a);
    for (int i = 0; i < q; i++) {
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
