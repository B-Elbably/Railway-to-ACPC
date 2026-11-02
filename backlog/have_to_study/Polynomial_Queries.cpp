#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node {
    int val;
    int lazy_m, lazy_c;
    bool has_lazy;
    Node(int v = 0) : val(v), lazy_m(0), lazy_c(0), has_lazy(false) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        return Node(a.val + b.val);
    }

    void apply(int x, int lx, int rx, int m, int c) {
        int cnt = rx - lx;
        int sum = (lx + rx - 1) * cnt / 2;
        seg[x].val += m * sum + c * cnt;
        seg[x].lazy_m += m;
        seg[x].lazy_c += c;
        seg[x].has_lazy = true;
    }

    void push(int x, int lx, int rx) {
        if (!seg[x].has_lazy || rx - lx == 1) return;
        int mid = (lx + rx) >> 1;
        apply(2 * x + 1, lx, mid, seg[x].lazy_m, seg[x].lazy_c);
        apply(2 * x + 2, mid, rx, seg[x].lazy_m, seg[x].lazy_c);
        seg[x].lazy_m = seg[x].lazy_c = 0;
        seg[x].has_lazy = false;
    }

    void build(const vector<int> &v, int x, int lx, int rx) {
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

    void update(int x, int lx, int rx, int l, int r, int m, int c) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            apply(x, lx, rx, m, c);
            return;
        }

        push(x, lx, rx);
        int mid = (lx + rx) >> 1;
        update(2 * x + 1, lx, mid, l, r, m, c);
        update(2 * x + 2, mid, rx, l, r, m, c);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        if (lx >= r || rx <= l) return Node(0);
        if (lx >= l && rx <= r) return seg[x];

        push(x, lx, rx);
        int mid = (lx + rx) >> 1;
        return merge(
            query(2 * x + 1, lx, mid, l, r),
            query(2 * x + 2, mid, rx, l, r)
        );
    }

public:
    SegmentTree(const vector<int> &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }

    void update(int l, int r, int m, int c) {
        update(0, 0, size, l, r, m, c);
    }

    int query(int l, int r) {
        return query(0, 0, size, l, r).val;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    SegmentTree seg(a);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            --l;
            seg.update(l, r, 1, 1 - l);
        }
        else {
            int l, r;
            cin >> l >> r;
            --l;
            cout << seg.query(l, r) << "\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}