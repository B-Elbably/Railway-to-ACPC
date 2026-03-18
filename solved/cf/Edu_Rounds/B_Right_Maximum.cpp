#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    int idx;
    Node(long long v = -1e18, int i = -1) : val(v), idx(i) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        if (a.val > b.val) return a;
        if (b.val > a.val) return b;
        return (a.idx > b.idx) ? a : b; 
    }

    void build(const vector<long long> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size())
                seg[x] = Node(v[lx], lx);
            return;
        }
        int mid = (lx + rx) >> 1;
        build(v, 2 * x + 1, lx, mid);
        build(v, 2 * x + 2, mid, rx);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        if (lx >= r || rx <= l) return Node();
        if (lx >= l && rx <= r) return seg[x];
        int mid = (lx + rx) >> 1;
        return merge(query(2 * x + 1, lx, mid, l, r), query(2 * x + 2, mid, rx, l, r));
    }

public:
    SegmentTree(const vector<long long> &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }

    int query(int l, int r) {
        return query(0, 0, size, l, r).idx;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    SegmentTree st(a);
    int l = 0, r = n;
    int ans = 0;
    while (l < r) {
        int nr = st.query(l, r);
        if (nr == -1) break; 
        r = nr;
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}