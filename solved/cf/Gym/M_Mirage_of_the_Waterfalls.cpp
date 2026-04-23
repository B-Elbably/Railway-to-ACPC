#include <bits/stdc++.h>
using namespace std;

struct Node {
    int pref, suff, max_val, sz;
    int lazy;
    
    Node(int v = 1, int size = 1) {
        sz = size;
        lazy = -1;
        if (v == 0) {
            pref = suff = max_val = sz;
        } else {
            pref = suff = max_val = 0;
        }
    }
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        if (a.sz == 0) return b;
        if (b.sz == 0) return a;
        
        Node res(1, a.sz + b.sz);
        res.pref = a.pref + (a.pref == a.sz ? b.pref : 0);
        res.suff = b.suff + (b.suff == b.sz ? a.suff : 0);
        res.max_val = max({a.max_val, b.max_val, a.suff + b.pref});
        return res;
    }

    void apply(int x, int v) {
        if (v == 0) {
            seg[x].pref = seg[x].suff = seg[x].max_val = seg[x].sz;
        } else {
            seg[x].pref = seg[x].suff = seg[x].max_val = 0;
        }
        seg[x].lazy = v;
    }

    void push(int x) {
        if (seg[x].lazy == -1 || seg[x].sz == 1) return;
        apply(2 * x + 1, seg[x].lazy);
        apply(2 * x + 2, seg[x].lazy);
        seg[x].lazy = -1;
    }

    void build(const vector<int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size()) {
                seg[x] = Node(v[lx], 1);
            }
            return;
        }
        int mid = (lx + rx) >> 1;
        build(v, 2 * x + 1, lx, mid);
        build(v, 2 * x + 2, mid, rx);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    void update(int x, int lx, int rx, int l, int r, int v) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            apply(x, v);
            return;
        }
        push(x);
        int mid = (lx + rx) >> 1;
        update(2 * x + 1, lx, mid, l, r, v);
        update(2 * x + 2, mid, rx, l, r, v);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        if (lx >= r || rx <= l) return Node(1, 0);
        if (lx >= l && rx <= r) return seg[x];
        
        push(x);
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
        seg.assign(2 * size, Node(1, 1));
        build(v, 0, 0, size);
    }

    void update(int l, int r, int v) {
        update(0, 0, size, l, r, v);
    }

    int query(int l, int r) {
        return query(0, 0, size, l, r).max_val;
    }
};

void solve() {
    int n, q, k;
    cin >> n >> q >> k;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    SegmentTree seg(a);

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--; r--;
        if (t == 1) {
            seg.update(l, r + 1, 0);
        } else {
            seg.update(l, r + 1, 1);
        }
        seg.query(0, n) >= k ? cout << "YES\n" : cout << "NO\n";
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