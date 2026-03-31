#include <bits/stdc++.h>
using namespace std;
// ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'



void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    ordered_set<pair<int, int>> st;
    for (int i = 0; i < n; i++) st.insert({a[i], i});
    while (q--)
    {
        char t;
        cin >> t;
        if (t == '?') {
            int a, b; cin >> a >> b;
            cout << st.order_of_key({b, n + 1}) - st.order_of_key({a, -1}) << endl;
        } else {
            int i, v; cin >> i >> v;
            --i;
            st.erase({a[i], i});
            a[i] = v;
            st.insert({a[i], i});
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
