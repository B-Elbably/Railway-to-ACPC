#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct Node {
    bool has_zero;
    Node(bool v = false) : has_zero(v) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        return Node(a.has_zero || b.has_zero);
    }

    void build(const vector<long long> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size())
                seg[x] = Node(v[lx] == 0);
            return;
        }

        int mid = (lx + rx) >> 1;
        build(v, 2 * x + 1, lx, mid);
        build(v, 2 * x + 2, mid, rx);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    void update(int x, int lx, int rx, int idx, long long v) {
        if (rx - lx == 1) {
            seg[x] = Node(v == 0);
            return;
        }

        int mid = (lx + rx) >> 1;
        if (idx < mid)
            update(2 * x + 1, lx, mid, idx, v);
        else
            update(2 * x + 2, mid, rx, idx, v);

        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    int query(int x, int lx, int rx, int l, int r) {
        if (lx >= r || rx <= l || !seg[x].has_zero) return -1;
        if (rx - lx == 1) return lx;

        int mid = (lx + rx) >> 1;
        int res = query(2 * x + 1, lx, mid, l, r);
        if (res != -1) return res;
        
        return query(2 * x + 2, mid, rx, l, r);
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

    int query(int l, int r) {
        return query(0, 0, size, l, r);
    }
};
const int N = 1.5e6 + 5;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> freq(N, 0);
    for (int i = 0; i < k; ++i) {
        freq[a[i]]++;
    }
    SegmentTree st(freq);
    int mex = st.query(0, N);
    for (int i = k; i < n; ++i) {
        freq[a[i - k]]--;
        st.update(a[i - k], freq[a[i - k]]);
        freq[a[i]]++;
        st.update(a[i], freq[a[i]]);
        mex = min(mex, st.query(0, N));
    }
    cout << mex << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
