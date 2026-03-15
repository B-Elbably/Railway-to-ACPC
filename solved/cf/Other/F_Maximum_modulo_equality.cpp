#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> seg;

    SegmentTree(const vector<int>& v) {
        n = v.size();
        seg.assign(4 * n, 0);
        build(v, 1, 0, n - 1);
    }

    void build(const vector<int>& v, int x, int lx, int rx) {
        if (lx == rx) {
            seg[x] = v[lx];
            return;
        }
        int mid = (lx + rx) / 2;
        build(v, 2*x, lx, mid);
        build(v, 2*x+1, mid+1, rx);
        seg[x] = gcd(seg[2*x], seg[2*x+1]);
    }

    int query(int x, int lx, int rx, int l, int r) {
        if (l > rx || r < lx) return 0;
        if (l <= lx && rx <= r) return seg[x];
        int mid = (lx + rx) / 2;
        return gcd(
            query(2*x, lx, mid, l, r),
            query(2*x+1, mid+1, rx, l, r)
        );
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> diffs(n);
    for (int i = 0; i < n-1; i++)
        diffs[i] = abs(a[i+1] - a[i]);
    SegmentTree seg(diffs);
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << 0 << " ";
        } else {
            r--;
            cout << seg.query(--l, --r) << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
}