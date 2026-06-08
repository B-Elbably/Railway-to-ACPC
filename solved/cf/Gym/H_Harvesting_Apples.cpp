#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
struct Node {
    long long val;
    Node(long long v = 0) : val(v) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        return Node(a.val + b.val);
    }

    void update(int x, int lx, int rx, int idx, long long v) {
        if (rx - lx == 1) {
            seg[x] = Node(v); // Set to new total value
            return;
        }
        int mid = (lx + rx) >> 1;
        if (idx < mid) update(2 * x + 1, lx, mid, idx, v);
        else update(2 * x + 2, mid, rx, idx, v);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        if (lx >= r || rx <= l) return Node(0);
        if (lx >= l && rx <= r) return seg[x];
        int mid = (lx + rx) >> 1;
        return merge(query(2 * x + 1, lx, mid, l, r), query(2 * x + 2, mid, rx, l, r));
    }

public:
    SegmentTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        seg.assign(2 * size, Node(0));
    }

    void update(int idx, long long v) {
        update(0, 0, size, idx, v);
    }

    long long query(int l, int r) {
        return query(0, 0, size, l, r).val;
    }
};

struct query {
    int d, l, r, idx;
};

struct up {
    int d, x;
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<query> queries(q);
    vector<up> day(m + 1);
    vector<int> mx(n + 1);
    for (int i = 1; i <= n; ++i) cin >> mx[i];
    for (int i = 1; i <= m; ++i) {
        cin >> day[i].d >> day[i].x;
    }
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].d >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }
    sort(all(queries), [](const query &a, const query &b) {
        return a.d < b.d;
    });

    vector<int> ans(q);
    SegmentTree seg(n + 1);
    int j = 0;
    for (int i = 1; i <= m; ++i) {
        int d = day[i].d;
        int x = day[i].x;
        int mxx = min(mx[d], seg.query(d, d + 1) + x);
        seg.update(d, mxx);
        while (j < q && queries[j].d == i) {
            ans[queries[j].idx] = seg.query(queries[j].l, queries[j].r + 1);
            j++;
        }
    }
    
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
