#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

template <typename T>
struct BIT {
    int n;
    vector<T> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}
    void add(int idx, T val) {
        for (++idx; idx <= n; idx += idx & -idx) {
            tree[idx] += val;
        }
    }
    T query(int idx) {
        T sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }

    T query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
    int lower_bound(T val) {
        T sum = 0;
        int pos = 0;
        for (int i = 1 << __lg(n); i > 0; i >>= 1) {
            if (pos + i <= n && sum + tree[pos + i] < val) {
                sum += tree[pos + i];
                pos += i;
            }
        }
        return pos;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    BIT<int> bit(n + 1);
    for (auto &x : a) cin >> x, bit.add(x, 1);
    while (q--) {
        int x; cin >> x;
        if (x > 0) bit.add(x, 1);
        else {
            x = -x;
            int idx = bit.lower_bound(x);
            bit.add(idx, -1);
        }
    }
    if (bit.query(1, n) == 0) cout << 0 << endl;
    else cout << bit.lower_bound(1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
