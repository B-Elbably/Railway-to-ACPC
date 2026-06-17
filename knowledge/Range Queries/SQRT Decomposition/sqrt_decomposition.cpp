#include <bits/stdc++.h>
using namespace std;

// SQRT Decomposition (Range Update, Range Sum Query with Lazy Propagation)
// Time Complexity:
//   - Build: O(N)
//   - Range Update: O(sqrt(N))
//   - Range Query: O(sqrt(N))
// Space Complexity: O(N)

class SqrtDecomposition {
private:
    int n;
    int block_size;
    int num_blocks;
    vector<long long> a;
    vector<long long> block_sum;
    vector<long long> block_lazy;

    // Helper to return the block index of a given array index
    inline int get_block(int idx) const {
        return idx / block_size;
    }

    // Helper to return the starting index of a given block
    inline int get_start(int block_idx) const {
        return block_idx * block_size;
    }

    // Helper to return the ending index (exclusive) of a given block
    inline int get_end(int block_idx) const {
        return min(n, (block_idx + 1) * block_size);
    }

    // Push the lazy value of a block down to its individual elements
    void push(int block_idx) {
        if (block_lazy[block_idx] == 0) return;
        int start = get_start(block_idx);
        int end = get_end(block_idx);
        for (int i = start; i < end; ++i) {
            a[i] += block_lazy[block_idx];
        }
        block_lazy[block_idx] = 0;
    }

public:
    SqrtDecomposition(const vector<long long>& input) {
        n = input.size();
        block_size = max(1, (int)sqrt(n));
        num_blocks = (n + block_size - 1) / block_size;
        
        a = input;
        block_sum.assign(num_blocks, 0);
        block_lazy.assign(num_blocks, 0);

        for (int i = 0; i < n; ++i) {
            block_sum[get_block(i)] += a[i];
        }
    }

    // Range Update: add val to all elements in range [l, r]
    void update(int l, int r, long long val) {
        int bl = get_block(l);
        int br = get_block(r);

        if (bl == br) {
            push(bl);
            for (int i = l; i <= r; ++i) {
                a[i] += val;
                block_sum[bl] += val;
            }
        } else {
            // Update partial left block
            push(bl);
            int end_l = get_end(bl);
            for (int i = l; i < end_l; ++i) {
                a[i] += val;
                block_sum[bl] += val;
            }

            // Update intermediate full blocks
            for (int b = bl + 1; b < br; ++b) {
                block_lazy[b] += val;
                block_sum[b] += val * (get_end(b) - get_start(b));
            }

            // Update partial right block
            push(br);
            int start_r = get_start(br);
            for (int i = start_r; i <= r; ++i) {
                a[i] += val;
                block_sum[br] += val;
            }
        }
    }

    // Range Query: return the sum of elements in range [l, r]
    long long query(int l, int r) {
        int bl = get_block(l);
        int br = get_block(r);
        long long sum = 0;

        if (bl == br) {
            push(bl);
            for (int i = l; i <= r; ++i) {
                sum += a[i];
            }
        } else {
            // Query partial left block
            push(bl);
            int end_l = get_end(bl);
            for (int i = l; i < end_l; ++i) {
                sum += a[i];
            }

            // Query intermediate full blocks
            for (int b = bl + 1; b < br; ++b) {
                sum += block_sum[b];
            }

            // Query partial right block
            push(br);
            int start_r = get_start(br);
            for (int i = start_r; i <= r; ++i) {
                sum += a[i];
            }
        }
        return sum;
    }
};

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    SqrtDecomposition sd(a);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) { // Range update
            int l, r;
            long long val;
            cin >> l >> r >> val;
            sd.update(l - 1, r - 1, val);
        } else { // Range query
            int l, r;
            cin >> l >> r;
            cout << sd.query(l - 1, r - 1) << "\n";
        }
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
