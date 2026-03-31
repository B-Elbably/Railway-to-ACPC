#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
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
        return Node(__gcd(a.val, b.val));   // change operation here
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

// [l, r) 0-indexed
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    vector<int> arr(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        arr[i] = abs(a[i + 1] - a[i]);
    }
    SegmentTree st(arr);
    int j = 0;

    for (int i = 0; i < n - 1; i++) {
        while (j <= i && st.query(j, i + 1) == 1) {
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans  + 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
