#include <bits/stdc++.h>
using namespace std;

struct Node {
    int freq[26];
    int lazy;

    Node(char c = 0) {
        memset(freq, 0, sizeof(freq));
        lazy = -1;
        if ('a' <= c && c <= 'z')
            freq[c - 'a']++;
    }
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;
    Node merge(const Node &a, const Node &b) {
        Node res;
        for (int i = 0; i < 26; i++) {
            res.freq[i] = a.freq[i] + b.freq[i];
        }
        return res;
    }
    void apply(int x, int lx, int rx, int c) {
        memset(seg[x].freq, 0, sizeof(seg[x].freq));
        seg[x].freq[c] = rx - lx;
        seg[x].lazy = c;
    }
    void push(int x, int lx, int rx) {
        if (seg[x].lazy == -1 || rx - lx == 1)
            return;
        int mid = (lx + rx) / 2;    
        apply(2 * x + 1, lx, mid, seg[x].lazy);
        apply(2 * x + 2, mid, rx, seg[x].lazy);
        seg[x].lazy = -1;
    }

    void build(string &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size())
                seg[x] = Node(v[lx]);
            return;
        }

        int mid = (lx + rx) >> 1;
        build(v, 2 * x + 1, lx, mid);
        build(v, 2 * x + 2, mid, rx);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    void update(int x, int lx, int rx, int l, int r, long long v) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            apply(x, lx, rx, v);
            return;
        }

        push(x, lx, rx);
        int mid = (lx + rx) >> 1;
        update(2 * x + 1, lx, mid, l, r, v);
        update(2 * x + 2, mid, rx, l, r, v);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }

    Node query(int x, int lx, int rx, int l, int r) {
        if (lx >= r || rx <= l) return Node();
        if (lx >= l && rx <= r) return seg[x];

        push(x, lx, rx);
        int mid = (lx + rx) >> 1;
        return merge(
            query(2 * x + 1, lx, mid, l, r),
            query(2 * x + 2, mid, rx, l, r)
        );
    }

public:
    SegmentTree(string &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }
    void update(int l, int r, long long v) {
        update(0, 0, size, l, r, v);
    }
    Node query(int l, int r) {
        return query(0, 0, size, l, r);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    SegmentTree seg(s);
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        --l;
        Node res = seg.query(l, r);
        if (k) {
            for (int i = 0; i < 26; i++) {
                if (res.freq[i]) {
                    seg.update(l, l + res.freq[i], i);
                    l += res.freq[i];
                }
            }
        }else {
            for (int i = 25; i >= 0; i--) {
                if (res.freq[i]) {
                    seg.update(l, l + res.freq[i], i);
                    l += res.freq[i];
                }
            }
        }
    }
    Node res = seg.query(0, n);
    for (int i = 0; i < n; i++) {
        Node cur = seg.query(i, i + 1);
        for (int c = 0; c < 26; c++) {
            if (cur.freq[c]) {
                cout << char('a' + c);
                break;
            }
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}