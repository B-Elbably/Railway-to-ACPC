#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    int l, r;
    Node(long long v = 0) : val(v), l(0), r(0) {}
};

class DynamicSegTree {
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

    void update(int x, long long lx, long long rx, long long idx, long long v) {
        if (rx - lx == 1) {
            seg[x].val += v;
            return;
        }
        long long mid = lx + (rx - lx) / 2;
        if (idx < mid) {
            if (!seg[x].l) seg[x].l = get_node();
            update(seg[x].l, lx, mid, idx, v);
        } else {
            if (!seg[x].r) seg[x].r = get_node();
            update(seg[x].r, mid, rx, idx, v);
        }
        Node left_node = seg[x].l ? seg[seg[x].l] : Node();
        Node right_node = seg[x].r ? seg[seg[x].r] : Node();
        seg[x].val = merge(left_node, right_node).val;
    }

    Node query(int x, long long lx, long long rx, long long l, long long r) {
        if (!x || lx >= r || rx <= l) return Node();
        if (lx >= l && rx <= r) return seg[x];
        long long mid = lx + (rx - lx) / 2;
        return merge(
            query(seg[x].l, lx, mid, l, r),
            query(seg[x].r, mid, rx, l, r)
        );
    }

public:
    int root;
    DynamicSegTree(long long max_v) {
        max_val = max_v;
        seg.push_back(Node());
        root = get_node();
    }

    void update(long long idx, long long v) {
        update(root, 0, max_val, idx, v);
    }

    long long query(long long l, long long r) {
        return query(root, 0, max_val, l, r).val;
    }
};

// [l, r)