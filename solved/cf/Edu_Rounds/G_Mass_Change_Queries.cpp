#include <bits/stdc++.h>
using namespace std;

const int N = 101;

struct Node {
    int mp[N];
    Node() {
        iota(mp, mp + N, 0);
    }
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;
    void apply(int x, int from, int to) {
        for (int i = 1; i < N; i++)
            if (seg[x].mp[i] == from)
                seg[x].mp[i] = to;
    }
    void push(int x) {
        for (int child : {2 * x + 1, 2 * x + 2}) {
            int tmp[N];
            for (int i = 1; i < N; i++)
                tmp[i] = seg[x].mp[ seg[child].mp[i] ];
            for (int i = 1; i < N; i++)
                seg[child].mp[i] = tmp[i];
        }
        iota(seg[x].mp, seg[x].mp + N, 0);
    }
    void update(int x, int lx, int rx, int l, int r, int from, int to) {
        if (rx <= l || r <= lx) return;
        if (l <= lx && rx <= r) {
            apply(x, from, to);
            return;
        }
        push(x);
        int mid = (lx + rx) / 2;
        update(2 * x + 1, lx, mid, l, r, from, to);
        update(2 * x + 2, mid, rx, l, r, from, to);
    }

    void query(int x, int lx, int rx, vector<int>& a) {
        if (rx - lx == 1) {
            if (lx < (int)a.size())
                a[lx] = seg[x].mp[a[lx]];
            return;
        }
        push(x);
        int mid = (lx + rx) / 2;
        query(2 * x + 1, lx, mid, a);
        query(2 * x + 2, mid, rx, a);
    }

public:
    SegmentTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        seg.assign(2 * size, Node());
    }

    void update(int l, int r, int from, int to) {
        update(0, 0, size, l, r, from, to);
    }

    void query(vector<int>& a) {
        query(0, 0, size, a);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    SegmentTree st(n);
    int q;
    cin >> q;
    while (q--) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        st.update(l - 1, r, x, y);
    }
    st.query(a);
    for (int x : a)
        cout << x << ' ';
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