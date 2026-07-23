#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    long long lazy;
    bool has_lazy;
    Node(long long v = 0) : val(v), lazy(0), has_lazy(false) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        return Node(a.val + b.val);
    }

    void apply(int x, int lx, int rx, long long v) {
        seg[x].val += (rx - lx) * v;
        seg[x].lazy += v;
        seg[x].has_lazy = true;
    }

    void push(int x, int lx, int rx) {
        if (!seg[x].has_lazy || rx - lx == 1) return;
        int mid = (lx + rx) >> 1;
        apply(2 * x + 1, lx, mid, seg[x].lazy);
        apply(2 * x + 2, mid, rx, seg[x].lazy);
        seg[x].lazy = 0;
        seg[x].has_lazy = false;
    }

    void build(const vector<long long> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size())
                seg[x] = Node(v[lx]);
            return;
        }

        int mid = (lx + rx) >> 1;
        build(v, 2 * x + 1, lx, mid);
        build(v, 2 * x + 2, mid, rx);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    void update(int x, int lx, int rx, int l, int r, long long v) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            apply(x, lx, rx, v);
            return;
        }

        push(x, lx, rx);
        int mid = (lx + rx) >> 1;
        update(2 * x + 1, lx, mid, l, r, v);
        update(2 * x + 2, mid, rx, l, r, v);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        if (lx >= r || rx <= l) return Node();
        if (lx >= l && rx <= r) return seg[x];

        push(x, lx, rx);
        int mid = (lx + rx) >> 1;
        return merge(
            query(2 * x + 1, lx, mid, l, r),
            query(2 * x + 2, mid, rx, l, r)
        );
    }

public:
    SegmentTree(const vector<long long> &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }

    void update(int l, int r, long long v) {
        update(0, 0, size, l, r, v);
    }

    long long query(int l, int r) {
        return query(0, 0, size, l, r).val;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    SegmentTree seg(a);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            long long v;
            cin >> l >> r >> v;
            seg.update(l, r, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}