template <typename T>
struct BIT {
    int n;
    vector<T> tree;
    BIT() {}
    BIT(int sz) {
        init(sz);
    }
    void init(int sz) {
        n = sz;
        tree.assign(n + 1, T());
    }
    // O(n)
    void build(const vector<T> &a) {
        init(a.size());
        for (int i = 1; i <= n; i++) {
            tree[i] += a[i - 1];
            int j = i + (i & -i);
            if (j <= n)
                tree[j] += tree[i];
        }
    }
    // a[idx] += val
    void add(int idx, T val) {
        for (++idx; idx <= n; idx += idx & -idx)
            tree[idx] += val;
    }
    // sum of [0..idx]
    T query(int idx) const {
        T res = T();
        for (++idx; idx > 0; idx -= idx & -idx)
            res += tree[idx];
        return res;
    }
    // sum of [l..r]
    T query(int l, int r) const {
        if (l > r) return T();
        return query(r) - (l ? query(l - 1) : T());
    }
    // value at idx
    T at(int idx) const {
        return query(idx, idx);
    }
    void set(int idx, T val) {
        add(idx, val - at(idx));
    }
    void clear() {
        fill(tree.begin(), tree.end(), T());
    }

    int lower_bound(T val) const {
        if (val <= 0) return 0;
        T sum = T();
        int pos = 0;
        int pw = 1;
        while ((pw << 1) <= n) pw <<= 1;
        for (; pw; pw >>= 1) {
            if (pos + pw <= n && sum + tree[pos + pw] < val) {
                sum += tree[pos + pw];
                pos += pw;
            }
        }
        return (pos == n ? n : pos);
    }
};