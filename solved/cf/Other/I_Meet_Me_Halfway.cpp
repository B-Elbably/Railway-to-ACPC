#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum1;
    long long sum2;
    Node(long long s1 = 0, long long s2 = 0) : sum1(s1), sum2(s2) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        return Node(a.sum1 + b.sum1, a.sum2 + b.sum2);
    }

    void build(const vector<long long> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size())
                seg[x] = Node(v[lx], 1LL * lx * v[lx]);
            return;
        }

        int mid = (lx + rx) >> 1;
        build(v, 2 * x + 1, lx, mid);
        build(v, 2 * x + 2, mid, rx);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    void update(int x, int lx, int rx, int idx, long long v) {
        if (rx - lx == 1) {
            seg[x] = Node(v, 1LL * lx * v);
            return;
        }

        int mid = (lx + rx) >> 1;
        if (idx < mid)
            update(2 * x + 1, lx, mid, idx, v);
        else
            update(2 * x + 2, mid, rx, idx, v);

        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        if (lx >= r || rx <= l) return Node();
        if (lx >= l && rx <= r) return seg[x];

        int mid = (lx + rx) >> 1;
        return merge(
            query(2 * x + 1, lx, mid, l, r),
            query(2 * x + 2, mid, rx, l, r)
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

    Node query(int l, int r) {
        return query(0, 0, size, l, r);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    vector<long long> a_prime(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        a_prime[i] = a[i % n];
    }

    SegmentTree seg(a_prime);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int idx;
            long long v;
            cin >> idx >> v;
            seg.update(idx, v);
            seg.update(idx + n, v);
        }
        else {
            int start_idx;
            cin >> start_idx;
            
            Node res = seg.query(start_idx, start_idx + n);
            cout << res.sum2 - 1LL * start_idx * res.sum1 << "\n";
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