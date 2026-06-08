#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e18;

struct Node {
    int pref, sum;
    Node(int v = 0) {
        sum = pref = v;
    }
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;
    
    Node merge(const Node &a, const Node &b) {
        Node res;
        res.sum = a.sum + b.sum;
        res.pref = max(a.pref, a.sum + b.pref);
        return res;
    }

    void build(const vector<int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size())
                seg[x] = Node(v[lx]);
            else {
                seg[x] = Node(-inf);
                seg[x].sum = 0;
            }
            return;
        }

        int mid = (lx + rx) >> 1;
        build(v, 2*x+1, lx, mid);
        build(v, 2*x+2, mid, rx);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    void update(int x, int lx, int rx, int idx, int v) {
        if (rx - lx == 1) {
            seg[x] = Node(v);
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
        if (lx >= r || rx <= l) {
            Node out;
            out.sum = 0;
            out.pref = -inf;
            return out;
        }
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
        return query(0, 0, size, l, r).pref;
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
            int idx; int v;
            cin >> idx >> v;
            seg.update(--idx, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << max(0LL, seg.query(--l, r)) << "\n";
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