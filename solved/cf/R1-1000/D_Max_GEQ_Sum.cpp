#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct Node {
    int mx, mn;
    Node(int mx = -1e18, int mn = 1e18) : mx(mx), mn(mn) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        Node res;
        res.mx = max(a.mx, b.mx);
        res.mn = min(a.mn, b.mn);
        return res;
    }

    void build(const vector<int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size())
                seg[x] = Node(v[lx], v[lx]);
            return;
        }

        int mid = (lx + rx) >> 1;
        build(v, 2*x+1, lx, mid);
        build(v, 2*x+2, mid, rx);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    void update(int x, int lx, int rx, int idx, int v) {
        if (rx - lx == 1) {
            seg[x] = Node(v, v);
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
    SegmentTree(const vector<int> &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }

    void update(int idx, int v) {
        update(0, 0, size, idx, v);
    }

    Node query(int l, int r) {
        return query(0, 0, size, l, r);
    }
};


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> L(n), R(n);
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }
    SegmentTree seg(pref);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        L[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] < a[i]) st.pop();
        R[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    bool ok = 1;
    for (int i = 0; i < n; ++i) {
        int mx = seg.query(i + 1, R[i] + 1).mx;
        int mn = seg.query(L[i] + 1, i + 1).mn;
        if (mx - pref[i] > a[i] || pref[i + 1] - mn > a[i]) {
            ok = 0;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
