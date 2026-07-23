#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

template <typename T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;

int get(ordered_multiset<int>& s, int val) {
    return s.order_of_key({val + 1, -1}) - s.order_of_key({val, -1});
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);   
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= k;
    }
    ordered_multiset<int> go, back;
    int res = 0;
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    for (int i = 0; i <= n; i++) {
        res += back.order_of_key({pref[i] + 1, -1});
        back.insert({pref[i], i});
    }
    back.clear();
    for (int i = 1; i <= n; i++) {
        back.insert({pref[i], i});
    }
    go.insert({pref[0], 0});
    int now = get(back, pref[0] - 1);
    int add = now;
    for (int i = 1; i < n; i++) {
        back.erase(back.lower_bound({pref[i], i}));
        now -= get(go, pref[i] + 1);
        now += get(back, pref[i] - 1);
        go.insert({pref[i], i});
        add = max(add, now);
    }
    cout << res + add << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}