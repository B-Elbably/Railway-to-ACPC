#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val = 0;
    long long lazy = 0;
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        return {a.val + b.val, 0};
    }

    void apply(int x, int lx, int rx, long long v) {
        seg[x].val += (rx - lx) * v;
        seg[x].lazy += v;
    }

    void push(int x, int lx, int rx) {
        if (seg[x].lazy == 0 || rx - lx == 1) return;

        int mid = (lx + rx) >> 1;
        apply(2*x+1, lx, mid, seg[x].lazy);
        apply(2*x+2, mid, rx, seg[x].lazy);
        seg[x].lazy = 0;
    }

    void update(int x, int lx, int rx, int l, int r, long long v) {
        if (lx >= r || rx <= l) return;

        if (lx >= l && rx <= r) {
            apply(x, lx, rx, v);
            return;
        }

        push(x, lx, rx);

        int mid = (lx + rx) >> 1;
        update(2*x+1, lx, mid, l, r, v);
        update(2*x+2, mid, rx, l, r, v);

        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        if (lx >= r || rx <= l) return Node();
        if (lx >= l && rx <= r) return seg[x];

        push(x, lx, rx);

        int mid = (lx + rx) >> 1;
        return merge(
            query(2*x+1, lx, mid, l, r),
            query(2*x+2, mid, rx, l, r)
        );
    }

public:
    SegmentTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        seg.assign(2 * size, Node());
    }

    void update(int l, int r, long long v) {
        update(0, 0, size, l, r, v);
    }

    long long query(int l, int r) {
        return query(0, 0, size, l, r).val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    SegmentTree seg(n);

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

// [l, r) 0-indexed