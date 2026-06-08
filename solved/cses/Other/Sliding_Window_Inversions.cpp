#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    ordered_set<pair<ll, int>> window;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += window.size() - window.order_of_key({a[i], n + 1});
        window.insert({a[i], i});
        if (i >= k) {
            sum -= window.order_of_key({a[i - k], i - k});
            window.erase({a[i - k], i - k});
        }
        if (i >= k - 1) {
            cout << sum << " ";
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
