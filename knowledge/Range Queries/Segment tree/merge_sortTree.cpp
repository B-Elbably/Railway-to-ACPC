#include <bits/stdc++.h>
using namespace std;

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

    int greater_(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) {
            return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), val);
        }
        int mid = start + (end - start) / 2;
        return greater_(2 * node, start, mid, l, r, val) +
               greater_(2 * node + 1, mid + 1, end, l, r, val);
    }

    int smaller_(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) {
            return lower_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
        }
        int mid = start + (end - start) / 2;
        return smaller_(2 * node, start, mid, l, r, val) +
               smaller_(2 * node + 1, mid + 1, end, l, r, val);
    }

public:
    MergeSortTree(const vector<long long>& a) {
        n = a.size();
        tree.resize(4 * n);
        if (n > 0) build(a, 1, 0, n - 1);
    }

    int greater_(int l, int r, long long val) {
        if (n == 0) return 0;
        return greater_(1, 0, n - 1, l, r, val);
    }

    int smaller_(int l, int r, long long val) {
        if (n == 0) return 0;
        return smaller_(1, 0, n - 1, l, r, val);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    MergeSortTree mst(a);

    while (q--) {
        int type, l, r;
        long long val;
        cin >> type >> l >> r >> val;
        l--; r--; 
        
        if (type == 1) cout << mst.greater_(l, r, val) << "\n";
        else cout << mst.smaller_(l, r, val) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}