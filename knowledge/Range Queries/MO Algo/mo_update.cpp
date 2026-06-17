#include <bits/stdc++.h>
using namespace std;

// Mo's Algorithm with Updates (3D Mo's)
// Time Complexity: O(N^(5/3) * Cost(add/remove))
// Space Complexity: O(N + Q + U)

struct MoWithUpdates {
    struct Query {
        int l, r, t, id;
        int bl, br;
        bool operator<(const Query& other) const {
            if (bl != other.bl) return bl < other.bl;
            if (br != other.br) return br < other.br;
            return t < other.t; // time order
        }
    };

    struct Update {
        int idx;
        int old_val;
        int new_val;
    };

    int n;
    int block_size;
    vector<Query> queries;
    vector<Update> updates;

    MoWithUpdates(int n) : n(n) {}

    void add_query(int l, int r, int id) {
        // t is the number of updates currently recorded
        queries.push_back({l, r, (int)updates.size(), id, 0, 0});
    }

    void add_update(int idx, int old_val, int new_val) {
        updates.push_back({idx, old_val, new_val});
    }

    // Dynamic block size optimization: block_size = N^(2/3)
    void calculate_block_size() {
        block_size = max(1, (int)pow(n, 2.0 / 3.0));
        for (auto& qry : queries) {
            qry.bl = qry.l / block_size;
            qry.br = qry.r / block_size;
        }
    }

    vector<int> solve(vector<int>& a) {
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
        for (const auto& upd : updates) {
            max_val = max({max_val, upd.old_val, upd.new_val});
        }
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

        auto apply_update = [&](int time_idx, int cur_l, int cur_r) {
            int idx = updates[time_idx].idx;
            int new_val = updates[time_idx].new_val;
            
            // If the updated index is inside current range, remove old and add new
            if (idx >= cur_l && idx <= cur_r) {
                remove(idx);
                a[idx] = new_val;
                add(idx);
            } else {
                a[idx] = new_val;
            }
        };

        auto rollback_update = [&](int time_idx, int cur_l, int cur_r) {
            int idx = updates[time_idx].idx;
            int old_val = updates[time_idx].old_val;
            
            // If the updated index is inside current range, remove new and add old
            if (idx >= cur_l && idx <= cur_r) {
                remove(idx);
                a[idx] = old_val;
                add(idx);
            } else {
                a[idx] = old_val;
            }
        };
        // ------------------------------

        int cur_l = 0, cur_r = -1, cur_t = 0;

        for (const auto& qry : queries) {
            // Adjust time coordinate
            while (cur_t < qry.t) {
                apply_update(cur_t, cur_l, cur_r);
                cur_t++;
            }
            while (cur_t > qry.t) {
                cur_t--;
                rollback_update(cur_t, cur_l, cur_r);
            }

            // Adjust range coordinates
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

        // Optional: restore array state to original by undoing updates
        while (cur_t > 0) {
            cur_t--;
            a[updates[cur_t].idx] = updates[cur_t].old_val;
        }

        return ans;
    }
};

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    vector<int> a(n);
    vector<int> cur_a(n); // keeps track of the current values of the array to record update histories
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cur_a[i] = a[i];
    }

    MoWithUpdates solver(n);
    int query_id = 0;
    
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) { // Range query
            int l, r;
            cin >> l >> r;
            solver.add_query(l - 1, r - 1, query_id++);
        } else { // Point update
            int idx, new_val;
            cin >> idx >> new_val;
            idx--; // convert to 0-indexed
            int old_val = cur_a[idx];
            solver.add_update(idx, old_val, new_val);
            cur_a[idx] = new_val; // update current tracked values
        }
    }

    vector<int> ans = solver.solve(a);
    for (int i = 0; i < (int)ans.size(); i++) {
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
