template <typename T>
struct BIT {
    int n;
    vector<T> tree;

    BIT(int n) : n(n), tree(n + 1, 0) {}

    void add(int idx, T val) {
        for (++idx; idx <= n; idx += idx & -idx) {
            tree[idx] += val;
        }
    }

    // 0 -> idx
    T query(int idx) {
        T sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }

    //l -> r
    T query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }

    // prefix_sum(i) >= val (lowest i)
    // must: non-negative values in BIT
    int lower_bound(T val) {
        T sum = 0;
        int pos = 0;
        for (int i = 1 << __lg(n); i > 0; i >>= 1) {
            if (pos + i <= n && sum + tree[pos + i] < val) {
                sum += tree[pos + i];
                pos += i;
            }
        }
        return pos;
    }
};