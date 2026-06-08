#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    int val;
    Node(int v = 0) : val(v) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        return Node(max(a.val, b.val));   // Changed operation to MAX
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
        if (lx >= r || rx <= l) return Node(0); // identity is 0 for positive max
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    if (n < 3) {
        cout << 0 << "\n";
        return;
    }
    vector<int> pref(n), suf(n);
    pref[0] = a[0];
    for(int i = 1; i < n; ++i) pref[i] = max(pref[i-1], a[i]);
    suf[n-1] = a[n-1];
    for(int i = n-2; i >= 0; --i) suf[i] = max(suf[i+1], a[i]);

    SegmentTree seg(a);
    int ans = 0;
    for(int i = 0; i < n - 2; ++i) {        
        int l = i + 1;
        int r = n - 2;
        int res = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int mx2 = seg.query(i + 1, mid + 1);
            int mx3 = suf[mid + 1];
            if (pref[i] + mx2 <= mx3) {
                res = mid; 
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        if (~res) ans += (res - i);
    }
    
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}