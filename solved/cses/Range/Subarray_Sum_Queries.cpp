#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9 + 7;
struct Node {
    ll ans, pref, suff, sum;
    Node(ll v = 0, ll p = 0, ll s = 0, ll su = 0) : ans(v), pref(v), suff(v), sum(v) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        Node res;
        res.sum = a.sum + b.sum;
        res.pref = max(a.pref, a.sum + b.pref);
        res.suff = max(b.suff, b.sum + a.suff);
        res.ans = max({0LL,a.ans, b.ans, a.suff + b.pref});
        return res;
    }

    void build(const vector<ll> &v, int x, int lx, int rx) {
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

    void update(int x, int lx, int rx, int idx, ll v) {
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
    SegmentTree(const vector<ll> &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }

    void update(int idx, ll v) {
        update(0, 0, size, idx, v);
    }

    ll query(int l, int r) {
        Node res = query(0, 0, size, l, r);
        // cout << "Query [" << l << ", " << r << "): ans = " << res.ans << ", pref = " << res.pref << ", suff = " << res.suff << ", sum = " << res.sum << "\n";
        return res.ans;
    }
};


void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    SegmentTree seg(a);
    while (q--) {
        int idx;
        ll v;
        cin >> idx >> v;
        seg.update(--idx, v);
        cout << max(0LL, seg.query(0, n)) << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}

// [l, r) 0-indexed