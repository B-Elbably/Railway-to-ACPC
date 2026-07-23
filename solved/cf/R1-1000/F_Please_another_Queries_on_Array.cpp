#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 301;
vector<vector<int>> factors(N);
vector<int> spf(N), primes, inv(N);
vector<uint64_t> vmask(N);

long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

struct Node {
    long long val;
    uint64_t mask;
    long long lazy;
    uint64_t lazy_mask;
    Node(long long v = 1, uint64_t m = 0) : val(v), mask(m), lazy(1), lazy_mask(0) {}
};

class SegmentTree {
private:
    int size;
    vector<Node> seg;

    Node merge(const Node &a, const Node &b) {
        return Node((a.val * b.val) % MOD, a.mask | b.mask);
    }

    void apply(int x, int lx, int rx, long long v, uint64_t m) {
        seg[x].val = (seg[x].val * power(v, rx - lx)) % MOD;
        seg[x].mask |= m;
        seg[x].lazy = (seg[x].lazy * v) % MOD;
        seg[x].lazy_mask |= m;
    }
    
    void push(int x, int lx, int rx) {
        if (seg[x].lazy == 1 && seg[x].lazy_mask == 0) return;
        int mid = (lx + rx) >> 1;
        apply(2 * x + 1, lx, mid, seg[x].lazy, seg[x].lazy_mask);
        apply(2 * x + 2, mid, rx, seg[x].lazy, seg[x].lazy_mask);
        seg[x].lazy = 1;
        seg[x].lazy_mask = 0;
    }

    void build(const vector<long long> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size())
                seg[x] = Node(v[lx], vmask[v[lx]]);
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
            apply(x, lx, rx, v, vmask[v]);
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
    SegmentTree(const vector<long long> &v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        seg.assign(2 * size, Node());
        build(v, 0, 0, size);
    }

    void update(int l, int r, long long v) {
        update(0, 0, size, l, r, v);
    }

    long long query(int l, int r) {
        Node res = query(0, 0, size, l, r);
        long long ans = res.val;
        for (int i = 0; i < primes.size(); ++i) {
            if (res.mask & (1ULL << i)) {
                ans = (ans * (primes[i] - 1)) % MOD;
                ans = (ans * inv[primes[i]]) % MOD;
            }
        }
        return ans;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    SegmentTree seg(a);

    while (q--) {
        string type;
        cin >> type;

        if (type == "MULTIPLY") {
            int l, r;
            long long v;
            cin >> l >> r >> v;
            seg.update(--l, r, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(--l, r) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i < N; ++i) spf[i] = i;
    for (int i = 2; i < N; ++i) {
        if (spf[i] != i) continue;
        primes.push_back(i);
        for (int j = i * i; j < N; j += i) {
            if (spf[j] == j) spf[j] = i;
        }
    }
    for (int i = 1; i < N; ++i) {
        uint64_t m = 0;
        for (int j = 0; j < primes.size(); ++j)
            if (i % primes[j] == 0) m |= (1ULL << j);
        vmask[i] = m;
        inv[i] = power(i, MOD - 2);
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}