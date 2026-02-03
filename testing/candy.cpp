#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    ll cnt, ans;
    char pref, suff;
    Node(ll c = 0, ll a = 0, char p = 'Z', char s = 'Z') : cnt(c), ans(a), pref(p), suff(s) {}
};

class SegmentTree {
private:
    vector<Node> seg;
    Node skip;
    int size = 1;

    Node merge(const Node &a, const Node &b) {
        Node res;
        if (a.pref == 'Z') return b;
        if (b.pref == 'Z') return a;
        res.pref = a.pref; res.suff = b.suff;
        res.ans = a.ans + b.ans;
        if (a.suff == b.pref) {
            res.cnt = a.cnt + b.cnt;
        } else {
            res.ans += a.cnt / 2;
            res.cnt = b.cnt;
        }
        return res;
    }

    void build(const vector<char> &v, int x, int lx, int rx) {
        if (lx == rx) {
            if (lx < (int)v.size())
                seg[x] = Node(1, 0, v[lx], v[lx]);
            return;
        }
        int mid = (lx + rx) >> 1;
        int l = x * 2 + 1;
        int r = x * 2 + 2;
        build(v, l, lx, mid);
        build(v, r, mid + 1, rx);
        seg[x] = merge(seg[l], seg[r]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        if (rx < l || lx > r) return skip;
        if (l <= lx && rx <= r) return seg[x];
        int mid = (lx + rx) >> 1;
        return merge(
            query(x * 2 + 1, lx, mid, l, r),
            query(x * 2 + 2, mid + 1, rx, l, r)
        );
    }

public:
    SegmentTree(const vector<char> &v) {
        skip = Node(0, 0, 'Z', 'Z');
        while (size < (int)v.size()) size <<= 1;
        seg.assign(size * 2, skip);
        build(v, 0, 0, size - 1);
    }

    ll query(int l, int r) {
        Node res = query(0, 0, size - 1, l, r);
        return res.ans + res.cnt / 2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    vector<char> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    SegmentTree sg(v);

    cin >> q;
    int l, r;
    while (q--) {
        cin >> l >> r;
        cout << sg.query(--l, --r) << '\n';
    }
}
