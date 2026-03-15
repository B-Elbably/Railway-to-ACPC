#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
struct Node {
    int val;
    Node(int v = -1) : val(v) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        if (a.val == -1) return b;
        if (b.val == -1) return a;
        return (arr[a.val] > arr[b.val] ? a : b);
    }

    void build(const vector<int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size())
                seg[x] = Node(lx);
            return;
        }
        int mid = (lx + rx) >> 1;
        build(v, 2*x+1, lx, mid);
        build(v, 2*x+2, mid, rx);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        if (lx >= r || rx <= l) return Node(-1);
        if (lx >= l && rx <= r) return seg[x];
        int mid = (lx + rx) >> 1;
        return merge(query(2*x+1, lx, mid, l, r), query(2*x+2, mid, rx, l, r));
    }

public:
    SegmentTree(const vector<int> &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }

    int query(int l, int r) {
        return query(0, 0, size, l, r).val;
    }
};

map<pair<int,int>, int> memo;

int dfs(int l, int r, SegmentTree &seg) {
    if (l > r) return 0;
    if (memo.count({l,r})) return memo[{l,r}];
    int ii = seg.query(l, r+1);
    return memo[{l,r}] = 1 + max(dfs(l, ii-1, seg),
                                dfs(ii+1, r, seg));
}

void solve() {
    int n;
    cin >> n;
    arr.resize(n);
    for (int &x: arr) cin >> x;
    memo.clear();
    SegmentTree seg(arr);
    cout << n - dfs(0, n-1, seg) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}