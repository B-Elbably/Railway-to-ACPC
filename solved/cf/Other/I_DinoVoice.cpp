#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int gg = 0;
struct Node {
    long long mx;
    long long val;
    Node(long long v = gg) : mx(v), val(0) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        Node res;
        res.mx = max(a.mx, b.mx);
        res.val = max({a.val, b.val, abs(a.mx - b.mx)});
        return res;
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
        if (lx >= r || rx <= l) return Node(gg); // identity
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    gg = a.back();
    // int nn = 1 << (int)(log2(n) + 1);
    // while (a.size() < nn) a.push_back(a.back());
    SegmentTree st(a);
    cout << st.query(0, n) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
