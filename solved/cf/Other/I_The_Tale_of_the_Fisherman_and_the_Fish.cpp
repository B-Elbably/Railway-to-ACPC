#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

class Treap {
private:
    struct node {
        int priority;
        int size = 1;
        node *left = nullptr, *right = nullptr;

        node(int v) : priority(rand()), val(v) {
            sum[0] = v, sum[1] = 0;
        }

        int val = 0;
        int64_t sum[2] = {0, 0};
        bool lazy_rev = false;
        int64_t lazy_add = 0;

        void apply(int v) {
            val += v;
            sum[0] += (size + 1) / 2 * v;
            sum[1] += size / 2 * v;
            lazy_add += v;
        }

        void pull() {
            size = 1;
            sum[0] = sum[1] = 0;
            int sz = left ? left->size : 0;
            sum[sz & 1] += val;
            if (left) {
                size += left->size;
                sum[0] += left->sum[0];
                sum[1] += left->sum[1];
            }
            if (right) {
                size += right->size;
                if ((sz + 1) & 1) {
                    sum[0] += right->sum[1];
                    sum[1] += right->sum[0];
                } else {
                    sum[0] += right->sum[0];
                    sum[1] += right->sum[1];
                }
            }
        }

        void push() {
            if (lazy_rev) {
                swap(left, right);
                if (left) left->lazy_rev = !left->lazy_rev;
                if (right) right->lazy_rev = !right->lazy_rev;
                lazy_rev = false;
            }
            if (lazy_add) {
                if (left) left->apply(lazy_add);
                if (right) right->apply(lazy_add);
                lazy_add = 0;
            }
        }
    };

    node *root = nullptr;

    int get_size(node *t) {
        return t ? t->size : 0;
    }

    void push(node *t) {
        if (t) t->push();
    }

    node *merge(node *left, node *right) {
        if (!left) return right;
        if (!right) return left;
        left->push();
        right->push();
        if (left->priority > right->priority) {
            left->right = merge(left->right, right);
            push(left->left);
            left->pull();
            return left;
        } else {
            right->left = merge(left, right->left);
            push(right->right);
            right->pull();
            return right;
        }
    }

    void split(node *t, int k, node *&left, node *&right) {
        if (!t) {
            left = right = nullptr;
            return;
        }
        push(t);
        int left_size = get_size(t->left);
        if (left_size >= k) {
            split(t->left, k, left, t->left);
            right = t;
            push(right->right);
            right->pull();
        } else {
            split(t->right, k - left_size - 1, t->right, right);
            left = t;
            push(left->left);
            left->pull();
        }
    }

public:
    Treap() {
        srand(time(0));
    }

    void insert(int pos, int val) {
        node *new_node = new node(val);
        node *left = nullptr, *right = nullptr;
        split(root, pos, left, right);
        root = merge(merge(left, new_node), right);
    }

    node *erase(int l, int r) {
        if (l > r) {
            return nullptr;
        }
        int n = get_size(root);
        if (l >= n || r < 0) {
            return nullptr;
        }
        if (l < 0) {
            l = 0;
        }
        if (r >= n) {
            r = n - 1;
        }
        node *left = nullptr, *mid = nullptr, *right = nullptr;
        split(root, l, left, mid);
        split(mid, r - l + 1, mid, right);
        root = merge(left, right);
        return mid;
    }

    pair<int64_t, int64_t> query(int l, int r) {
        node *left = nullptr, *mid = nullptr, *right = nullptr;
        split(root, l, left, mid);
        split(mid, r - l + 1, mid, right);
        int64_t e = 0, o = 0;
        if (mid) {
            e = mid->sum[0];
            o = mid->sum[1];
        }
        root = merge(merge(left, mid), right);
        return {e, o};
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    Treap t;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        t.insert(i, x);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        auto nd = t.erase(l, l);
        t.insert(r, nd->val);
        auto [e,o] = t.query(0, n - 1);
        if (e > o)cout << "FISH";
        else if (e == o)cout << "TIE";
        else cout << "MAN";
        cout << endl;
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

