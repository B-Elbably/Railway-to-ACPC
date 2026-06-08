#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct Node {
    int val;
    Node(int v = LLONG_MAX) : val(v) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        return Node(min(a.val, b.val));   // change operation here
    }

    void build(const vector<int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size())
                seg[x] = Node(v[lx]);
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
        if (lx >= r || rx <= l) return Node(); // identity
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
        return query(0, 0, size, l, r).val;
    }
};


void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n), b(n);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i] = x + i + 1;
        b[i] = x - i - 1;
    }
    SegmentTree segA(a), segB(b);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int idx;
            int v;
            cin >> idx >> v;
            segA.update(idx - 1, v + idx);
            segB.update(idx - 1, v - idx);
        }
        else {
            int idx;
            cin >> idx;
            int ans = min(
                segB.query(0, idx) + idx,
                segA.query(idx - 1, n) - idx
            );
            cout << ans << endl;
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