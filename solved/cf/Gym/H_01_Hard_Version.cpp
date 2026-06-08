#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'


struct Node {
    int c0, c1;
    Node(int c0 = 0, int c1 = 0) : c0(c0), c1(c1) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        Node res;
        int m = min(a.c0, b.c1);
        res.c0 = a.c0 + b.c0 - m;
        res.c1 = a.c1 + b.c1 - m;
        return res;
    }

    void build(const vector<int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size())
                seg[x] = Node(v[lx] == 0, v[lx] == 1);
            return;
        }

        int mid = (lx + rx) >> 1;
        build(v, 2*x+1, lx, mid);
        build(v, 2*x+2, mid, rx);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    void update(int x, int lx, int rx, int idx, int v) {
        if (rx - lx == 1) {
            seg[x] = Node(v == 0, v == 1);
            return;
        }

        int mid = (lx + rx) >> 1;
        if (idx < mid)
            update(2*x+1, lx, mid, idx, v);
        else
            update(2*x+2, mid, rx, idx, v);

        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        if (lx >= r || rx <= l) return Node(0, 0); // identity
        if (lx >= l && rx <= r) return seg[x];

        int mid = (lx + rx) >> 1;
        return merge(
            query(2*x+1, lx, mid, l, r),
            query(2*x+2, mid, rx, l, r)
        );
    }

public:
    SegmentTree(const vector<int> &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }

    void update(int idx, int v) {
        update(0, 0, size, idx, v);
    }

    int query(int l, int r) {
        Node res = query(0, 0, size, l, r);
        return res.c0 + res.c1;
    }
};


void solve() {
    string ss; cin >> ss;
    int n = (int)ss.size();
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {a[i] = ss[i] - '0';}
    SegmentTree seg(a);
    
    int q; cin >> q;    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int idx; cin >> idx;
            a[--idx] ^= 1;
            seg.update(idx, a[idx]);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(--l, r) << "\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}

// [l, r) 0-indexed