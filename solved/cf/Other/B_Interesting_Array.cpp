#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node(int v = 0) : val(v) {}
};

class SegmentTree {
private:
    vector<Node> seg;
    vector<int> lazy;
    Node skip = Node((1 << 30) - 1);
    int size = 1;

    Node merge(const Node &a, const Node &b) {
        return Node(a.val & b.val);
    }

    void push(int x, int lx, int rx) {
        if (lazy[x] == 0) return;
        seg[x].val |= lazy[x];
        if (lx != rx) {
            lazy[2*x+1] |= lazy[x];
            lazy[2*x+2] |= lazy[x];
        }
        lazy[x] = 0;
    }

    void build(const vector<int> &v, int x, int lx, int rx) {
        if (lx == rx) {
            if (lx < (int)v.size())
                seg[x] = Node(v[lx]);
            return;
        }
        int mid = (lx + rx) >> 1;
        build(v, 2*x+1, lx, mid);
        build(v, 2*x+2, mid+1, rx);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    void update(int x, int lx, int rx, int l, int r, int val) {
        push(x, lx, rx);
        if (lx > r || rx < l) return;
        if (l <= lx && rx <= r) {
            lazy[x] |= val;
            push(x, lx, rx);
            return;
        }
        int mid = (lx + rx) >> 1;
        update(2*x+1, lx, mid, l, r, val);
        update(2*x+2, mid+1, rx, l, r, val);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        push(x, lx, rx);
        if (lx > r || rx < l) return skip;
        if (l <= lx && rx <= r) return seg[x];
        int mid = (lx + rx) >> 1;
        return merge(
            query(2*x+1, lx, mid, l, r),
            query(2*x+2, mid+1, rx, l, r)
        );
    }

public:
    SegmentTree(const vector<int> &v) {
        while (size < (int)v.size()) size <<= 1;
        seg.assign(size << 1, Node(0));
        lazy.assign(size << 1, 0);
        build(v, 0, 0, size - 1);
    }

    void update(int l, int r, int val) {
        update(0, 0, size - 1, l, r, val);
    }

    int query(int l, int r) {
        return query(0, 0, size - 1, l, r).val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> queries(m, vector<int>(3));
    for (int i = 0; i < m; ++i)
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];

    SegmentTree sg(vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int l = queries[i][0] - 1;
        int r = queries[i][1] - 1;
        sg.update(l, r, queries[i][2]);
    }

    for (int i = 0; i < m; ++i) {
        int l = queries[i][0] - 1;
        int r = queries[i][1] - 1;
        if (sg.query(l, r) != queries[i][2]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << sg.query(i, i) << " ";
}