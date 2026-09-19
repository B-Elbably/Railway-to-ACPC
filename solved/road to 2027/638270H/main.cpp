#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e5 + 5;
template <typename T>
struct BIT {
    int n;
    vector<T> tree;
    BIT() {}
    BIT(int sz) {
        init(sz);
    }
    void init(int sz) {
        n = sz;
        tree.assign(n + 1, T());
    }
    // O(n)
    void build(const vector<T> &a) {
        init(a.size());
        for (int i = 1; i <= n; i++) {
            tree[i] += a[i - 1];
            int j = i + (i & -i);
            if (j <= n)
                tree[j] += tree[i];
        }
    }
    // a[idx] += val
    void add(int idx, T val) {
        for (++idx; idx <= n; idx += idx & -idx)
            tree[idx] += val;
    }
    // sum of [0..idx]
    T query(int idx) const {
        T res = T();
        for (++idx; idx > 0; idx -= idx & -idx)
            res += tree[idx];
        return res;
    }
    // sum of [l..r]
    T query(int l, int r) const {
        if (l > r) return T();
        return query(r) - (l ? query(l - 1) : T());
    }
    // value at idx
    T at(int idx) const {
        return query(idx, idx);
    }
    void set(int idx, T val) {
        add(idx, val - at(idx));
    }
    void clear() {
        fill(tree.begin(), tree.end(), T());
    }

    int lower_bound(T val) const {
        if (val <= 0) return 0;
        T sum = T();
        int pos = 0;
        int pw = 1;
        while ((pw << 1) <= n) pw <<= 1;
        for (; pw; pw >>= 1) {
            if (pos + pw <= n && sum + tree[pos + pw] < val) {
                sum += tree[pos + pw];
                pos += pw;
            }
        }
        return (pos == n ? n : pos);
    }
};
const int S = 320; 

vector<int> vals(N);
BIT<int> bit(N);
struct Query {
    int l, r, k, id;
    bool operator<(Query const& o) const {
        if (l / S != o.l / S)
            return l / S < o.l / S;
        return ((l / S) & 1) ? r > o.r : r < o.r;
    }
};
int m;
vector<int> a;
int ans = 0;

inline void add(int idx) {
    bit.add(a[idx], vals[a[idx]]);
}

inline void remove(int idx) {
    bit.add(a[idx], -vals[a[idx]]);
}

vector<int> mo_algorithm(vector<Query>& queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    int curr_l = 0;
    int curr_r = -1;

    for (Query q : queries) {
        while (curr_l > q.l) add(--curr_l);
        while (curr_r < q.r) add(++curr_r);
        while (curr_l < q.l) remove(curr_l++);
        while (curr_r > q.r) remove(curr_r--);
        int p = upper_bound(vals.begin() + 1, vals.begin() + m + 1, q.k) - vals.begin() - 1;
        answers[q.id] = bit.query(p);
    }
    return answers;
}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x;
    vector<int> arr = a;
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    m = arr.size();
    auto get = [&](int x) {
        return lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    };
    for (int i = 0; i < n; i++) {
        vals[get(a[i]) + 1] = a[i];
    }
    for (auto &x : a) x = get(x) + 1;
    int q; cin >> q;
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        cin >> queries[i].k;
        queries[i].l--, queries[i].r--;
        queries[i].id = i;
    }
    vector<int> answers = mo_algorithm(queries);
    for (int x : answers) cout << x << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
