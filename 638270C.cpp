#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct ImplicitTreap {
    struct Node {
        long long val, sum;
        int prior, sz;
        Node *l, *r;
        Node(long long v) : val(v), sum(v), prior(rng()), sz(1), l(nullptr), r(nullptr) {}
    };

    typedef Node* pnode;
    pnode root;

    ImplicitTreap() {
        root = nullptr;
    }

    int sz(pnode t) {
        return t ? t->sz : 0;
    }

    long long get_sum(pnode t) {
        return t ? t->sum : 0;
    }

    void merge(pnode t) {
        if (!t) return;
        t->sz = sz(t->l) + 1 + sz(t->r);
        t->sum = get_sum(t->l) ^ t->val ^ get_sum(t->r);
    }

    void split(pnode t, pnode &l, pnode &r, int key, int add = 0) {
        if (!t) return void(l = r = nullptr);
        int cur_key = add + sz(t->l) + 1;
        if (key >= cur_key) {
            split(t->r, t->r, r, key, cur_key);
            l = t;
        } else {
            split(t->l, l, t->l, key, add);
            r = t;
        }
        merge(t);
    }

    void combine(pnode &t, pnode l, pnode r) {
        if (!l || !r) {
            t = l ? l : r;
        } else if (l->prior > r->prior) {
            combine(l->r, l->r, r);
            t = l;
        } else {
            combine(r->l, l, r->l);
            t = r;
        }
        merge(t);
    }

    void insert(int pos, long long val) {
        pnode t1, t2;
        split(root, t1, t2, pos - 1);
        combine(t1, t1, new Node(val));
        combine(root, t1, t2);
    }

    void erase(int pos) {
        pnode t1, t2, t3;
        split(root, t1, t2, pos - 1);
        split(t2, t2, t3, 1);
        delete t2;
        combine(root, t1, t3);
    }

    long long query(int L, int R) {
        pnode t1, t2, t3;
        split(root, t1, t2, L - 1);
        split(t2, t2, t3, R - L + 1);
        long long ans = get_sum(t2);
        combine(root, t1, t2);
        combine(root, root, t3);
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int q; cin >> q;
    ImplicitTreap treap;
    for (int i = 0; i < n; ++i) treap.insert(i + 1, a[i]);
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int idx, val;
            cin >> idx >> val;
            treap.insert(idx, val);
        } else if (type == 2) {
            int idx; cin >> idx;
            treap.erase(idx);
        } else {
            int l, r; cin >> l >> r;
            cout << treap.query(l, r) << endl;
        }
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
