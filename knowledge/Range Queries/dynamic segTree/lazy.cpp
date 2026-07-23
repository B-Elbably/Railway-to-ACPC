#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    long long lazy;
    bool has_lazy;
    int l, r;
    Node(long long v = 0) : val(v), lazy(0), has_lazy(false), l(0), r(0) {}
};

class LazyDynamicSegTree {
private:
    long long max_val;
    vector<Node> seg;

    int get_node() {
        seg.push_back(Node());
        return seg.size() - 1;
    }

    Node merge(const Node &a, const Node &b) {
        return Node(a.val + b.val);
    }

    void apply(int x, long long lx, long long rx, long long v) {
        seg[x].val += (rx - lx) * v;
        seg[x].lazy += v;
        seg[x].has_lazy = true;
    }

    void push(int x, long long lx, long long rx) {
        if (!seg[x].has_lazy || rx - lx == 1) return;
        if (!seg[x].l) seg[x].l = get_node();
        if (!seg[x].r) seg[x].r = get_node();
        long long mid = lx + (rx - lx) / 2;
        apply(seg[x].l, lx, mid, seg[x].lazy);
        apply(seg[x].r, mid, rx, seg[x].lazy);
        seg[x].lazy = 0;
        seg[x].has_lazy = false;
    }

    void update(int x, long long lx, long long rx, long long l, long long r, long long v) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            apply(x, lx, rx, v);
            return;
        }
        push(x, lx, rx);
        long long mid = lx + (rx - lx) / 2;
        if (!seg[x].l) seg[x].l = get_node();
        if (!seg[x].r) seg[x].r = get_node();
        update(seg[x].l, lx, mid, l, r, v);
        update(seg[x].r, mid, rx, l, r, v);
        
        Node left_node = seg[seg[x].l];
        Node right_node = seg[seg[x].r];
        seg[x].val = merge(left_node, right_node).val;
    }

    Node query(int x, long long lx, long long rx, long long l, long long r) {
        if (!x || lx >= r || rx <= l) return Node();
        if (lx >= l && rx <= r) return seg[x];
        push(x, lx, rx);
        long long mid = lx + (rx - lx) / 2;
        return merge(
            query(seg[x].l, lx, mid, l, r),
            query(seg[x].r, mid, rx, l, r)
        );
    }

public:
    int root;
    LazyDynamicSegTree(long long max_v) {
        max_val = max_v;
        seg.push_back(Node());
        root = get_node();
    }

    void update(long long l, long long r, long long v) {
        update(root, 0, max_val, l, r, v);
    }

    long long query(long long l, long long r) {
        return query(root, 0, max_val, l, r).val;
    }
};

// [l, r)