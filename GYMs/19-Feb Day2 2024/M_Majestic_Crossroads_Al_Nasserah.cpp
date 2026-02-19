#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct Node {
    int val;
    Node(int v = 0) : val(v) {}
};

class SegmentTree {
private:
    vector<Node> seg;
    Node skip = Node(0);
    int size = 1;

    Node merge(const Node &a, const Node &b) {
        return Node(a.val + b.val);
    }

    void build(const vector<int> &v, int x, int lx, int rx) {
        if (lx == rx) {
            if (lx < v.size()) seg[x] = Node(v[lx]);
            return;
        }
        int mid = (lx + rx) >> 1;
        int left = (x << 1) | 1;
        int right = (x << 1) + 2;
        build(v, left, lx, mid);
        build(v, right, mid + 1, rx);
        seg[x] = merge(seg[left], seg[right]);
    }

    void update(int x, int lx, int rx, int idx, int value) {
        if (lx == rx) {
            seg[x] = Node(value);
            return;
        }
        int mid = (lx + rx) >> 1;
        int left = (x << 1) | 1;
        int right = (x << 1) + 2;
        if (idx <= mid) update(left, lx, mid, idx, value);
        else update(right, mid + 1, rx, idx, value);
        seg[x] = merge(seg[left], seg[right]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        if (lx > r || rx < l) return skip;
        if (l <= lx && rx <= r) return seg[x];
        int mid = (lx + rx) >> 1;
        int left = (x << 1) | 1;
        int right = (x << 1) + 2;
        return merge(query(left, lx, mid, l, r),
                        query(right, mid + 1, rx, l, r));
    }

public:
    SegmentTree(const vector<int> &v) {
        while (size < v.size()) size <<= 1;
        seg.assign(size << 1, skip);
        build(v, 0, 0, size - 1);
    }

    void update(int idx, int value) {
        update(0, 0, size - 1, idx, value);
    }

    int query(int l, int r) {
        return query(0, 0, size - 1, l, r).val;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<pair<int,int>> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b.begin(), b.end());
    SegmentTree seg(vector<int>(n, 1));
    for (int i = n - 1; i >= 0; i--) {
        int idx = b[i].second;
        if (seg.query(0, idx) & 1)
            cout << "Bakkar" << endl;
        else
            cout << "Rashida" << endl;
        seg.update(idx, 0);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
} 
