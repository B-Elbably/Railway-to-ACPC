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
        for (++idx; idx <= n; idx += idx & -idx)
            tree[idx] += val;
    }
    T query(int idx) {
        T res = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            res += tree[idx];
        return res;
    }
    T query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

struct Event {
    int val;
    int l, r;
    int sign;
    int id;
    bool operator<(const Event &other) const {
        return val < other.val;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    vector<Event> events;
    events.reserve(2 * q);
    for (int i = 0; i < q; i++) {
        int l, r, c, d;
        cin >> l >> r >> c >> d;
        --l, --r;
        events.push_back({d, l, r, 1, i});
        events.push_back({c - 1, l, r, -1, i});
    }
    sort(events.begin(), events.end());
    BIT<int> bit(n);
    vector<int> ans(q);
    int ptr = 0;
    for (auto &e : events) {
        while (ptr < n && a[ptr].first <= e.val) {
            bit.add(a[ptr].second, 1);
            ptr++;
        }
        ans[e.id] += e.sign * bit.query(e.l, e.r);
    }
    for (int x : ans) cout << x << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
