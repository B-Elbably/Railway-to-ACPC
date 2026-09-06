#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

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

struct line {
    int x, y1, y2, type;
    bool operator<(const line &other) const {
        if (x != other.x) return x < other.x;
        return type < other.type;
    }
};
const int N = 2e6 + 5;
const int shift = 1e6 + 1;

void solve() {
    int n;
    cin >> n;
    BIT<int> bit(N);
    int x1, y1, x2, y2;
    vector<line> lines;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        y1 += shift;
        y2 += shift;
        if (x1 == x2) {
            lines.push_back({x1, min(y1, y2), max(y1, y2), 2});
        } else {
            lines.push_back({min(x1, x2), y1, y2, 1});
            lines.push_back({max(x1, x2), y1, y2, 3});
        }
    }
    sort(all(lines));
    int ans = 0;
    for (const auto &l : lines) {
        if (l.type == 1) {
            bit.add(l.y1, 1);
        } else if (l.type == 2) {
            ans += bit.query(l.y1, l.y2);
        } else {
            bit.add(l.y1, -1);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
