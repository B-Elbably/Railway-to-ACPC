#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct Range {
    int l, r, id;
};

void solve() {
    int n;
    cin >> n;
    vector<Range> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(all(a), [](const Range &x, const Range &y) {
        if (x.l == y.l) return x.r > y.r;
        return x.l < y.l;
    });
    vector<int> contains(n), contained(n);
    ordered_set s;
    for (int i = 0; i < n; i++) {
        contained[a[i].id] = i - s.order_of_key({a[i].r, -1});
        s.insert({a[i].r, i});
    }

    s.clear();
    for (int i = n - 1; i >= 0; i--) {
        contains[a[i].id] = s.order_of_key({a[i].r, n + 1});
        s.insert({a[i].r, i});
    }

    for (int x: contains) cout << x << " ";
    cout << endl;
    for (int x: contained) cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}