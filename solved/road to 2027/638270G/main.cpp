#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct SegTree {
    int n;
    vector<vector<int>> tree;
    vector<int> lazy;

    SegTree(int n) : n(n), tree(4 * max(1LL, n), vector<int>(26, 0)), lazy(4 * max(1LL, n), -1) {}

    void push(int node, int l, int r) {
        if (lazy[node] != -1) {
            int mid = l + (r - l) / 2;
            int c = lazy[node];
            for (int i = 0; i < 26; i++) {
                tree[2 * node][i] = tree[2 * node + 1][i] = 0;
            }
            tree[2 * node][c] = mid - l + 1;
            tree[2 * node + 1][c] = r - mid;
            lazy[2 * node] = lazy[2 * node + 1] = c;
            lazy[node] = -1;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int c) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            for (int i = 0; i < 26; i++) tree[node][i] = 0;
            tree[node][c] = r - l + 1;
            lazy[node] = c;
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, ql, qr, c);
        update(2 * node + 1, mid + 1, r, ql, qr, c);
        for (int i = 0; i < 26; i++) tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
    }

    int query(int node, int l, int r, int ql, int qr, int c) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node][c];
        push(node, l, r);
        int mid = l + (r - l) / 2;
        return query(2 * node, l, mid, ql, qr, c) + query(2 * node + 1, mid + 1, r, ql, qr, c);
    }

    void update(int ql, int qr, char c) {
        if (ql <= qr) update(1, 0, n - 1, ql, qr, c - 'a');
    }

    int query(int ql, int qr, char c) {
        return ql > qr ? 0 : query(1, 0, n - 1, ql, qr, c - 'a');
    }
};

struct ParityTree {
    SegTree even, odd;

    ParityTree(int n) : even(n / 2), odd((n + 1) / 2) {}

    void update(int l, int r, char c, bool isOdd) {
        if (isOdd) {
            odd.update(l / 2, (r - 1) / 2, c);
        } else {
            even.update((l - 1) / 2, r / 2 - 1, c);
        }
    }

    int query(int l, int r, char c, bool isOdd) {
        if (isOdd) {
            return odd.query(l / 2, (r - 1) / 2, c);
        }
        return even.query((l - 1) / 2, r / 2 - 1, c);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    
    ParityTree pt(n);
    for (int i = 0; i < n; i++) {
        pt.update(i + 1, i + 1, s[i], (i + 1) & 1);
    }
    
    while (q--) {
        string op;
        cin >> op;
        if (op == "SET") {
            int l, r;
            char c;
            cin >> l >> r >> c;
            pt.update(l, r, c, true);
            pt.update(l, r, c, false);
        } else if (op == "QUERY") {
            int l, r;
            cin >> l >> r;
            if (l == r) {
                cout << "YES" << endl;
                continue;
            }
            
            char c1 = 'a', c2 = 'a';
            for(int i = 0; i < 26; i++) {
                if (pt.query(l, l, i + 'a', l & 1)) c1 = i + 'a';
                if (pt.query(l + 1, l + 1, i + 'a', (l + 1) & 1)) c2 = i + 'a';
            }
            if (c1 == c2) {
                cout << "NO" << endl;
                continue;
            }
            int od = pt.query(l, r, c1, true);
            int ev = pt.query(l, r, c2, false);
            if (od + ev == r - l + 1) {
                cout << "YES" << endl;
            } else {
                od = pt.query(l, r, c2, true);
                ev = pt.query(l, r, c1, false);
                if (od + ev == r - l + 1) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;  
                }
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qrTNum;
    cin >> qrTNum;

    while (qrTNum--)
        solve();

    return 0;
}