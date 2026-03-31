#include <bits/stdc++.h>
using namespace std;

struct Node {
    int mx, pre, suf, sz, lb, rb;
    Node(int bit = -1) {
        if (bit == -1) { mx = pre = suf = sz = 0; lb = rb = -1; }
        else { mx = pre = suf = sz = 1; lb = rb = bit; }
    }
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &L, const Node &R) {
        if (L.sz == 0) return R;
        if (R.sz == 0) return L;
        Node res;
        res.sz = L.sz + R.sz;
        res.lb = L.lb; res.rb = R.rb;
        res.mx = max(L.mx, R.mx);
        res.pre = L.pre; res.suf = R.suf;
        if (L.rb == R.lb) {
            res.mx = max(res.mx, L.suf + R.pre);
            if (L.pre == L.sz) res.pre = L.sz + R.pre;
            if (R.suf == R.sz) res.suf = R.sz + L.suf;
        }
        return res;
    }

    void build(const vector<int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size()) seg[x] = Node(v[lx]);
            return;
        }
        int mid = (lx + rx) >> 1;
        build(v, 2*x+1, lx, mid);
        build(v, 2*x+2, mid, rx);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    void update(int x, int lx, int rx, int idx) {
        if (rx - lx == 1) {
            seg[x] = Node(1 - seg[x].lb); // Flip bit
            return;
        }
        int mid = (lx + rx) >> 1;
        if (idx < mid) update(2*x+1, lx, mid, idx);
        else update(2*x+2, mid, rx, idx);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

public:
    SegmentTree(const vector<int> &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }
    void update(int idx) { update(0, 0, size, idx); }
    int query() { return seg[0].mx; }
};

void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> a(n);
    for(int i=0; i<n; i++) a[i] = s[i]-'0';
    SegmentTree st(a);
    int m; cin >> m;
    while(m--) {
        int x; cin >> x;
        st.update(x-1);
        cout << st.query() << " ";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}