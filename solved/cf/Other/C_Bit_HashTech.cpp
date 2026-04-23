#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    Node(long long v = 0) : val(v) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        return Node(a.val + b.val);   // change operation here
    }

    void build(const vector<long long> &v, int x, int lx, int rx) {
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

    void update(int x, int lx, int rx, int idx, long long v) {
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
        if (lx >= r || rx <= l) return Node(0); // identity
        if (lx >= l && rx <= r) return seg[x];

        int mid = (lx + rx) >> 1;
        return merge(
            query(2*x+1, lx, mid, l, r),
            query(2*x+2, mid, rx, l, r)
        );
    }

public:
    SegmentTree(const vector<long long> &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }

    void update(int idx, long long v) {
        update(0, 0, size, idx, v);
    }

    long long query(int l, int r) {
        return query(0, 0, size, l, r).val;
    }
};


void solve() {
    int q; cin >> q;
    vector<long long> v(33, 0);
    SegmentTree st(v);
    map<int, multiset<int>> pos;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x; cin >> x;
            int cnt = __builtin_popcount(x);
            pos[cnt].insert(x);
            st.update(cnt, st.query(cnt, cnt + 1) + x);
        }else if (type == 2) {
            int n; cin >> n;
            if (pos[n].empty()) continue;
            st.update(n, st.query(n, n + 1) - *pos[n].begin());
            pos[n].erase(pos[n].begin());
        }else {
            int l, r; cin >> l >> r;
            cout << st.query(l, r + 1) << "\n";
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
}

// [l, r) 0-indexed