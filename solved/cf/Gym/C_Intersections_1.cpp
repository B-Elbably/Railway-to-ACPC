#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    map<int, int> idx1, idx2;
    for (int i = 0; i < n; i++) {
        idx1[a[i]] = i;
        idx2[b[i]] = i;
    }
    int ans = 0;
    ordered_set<int> s;
    for (int i = 0; i < n; i++) {
        ans += s.size() - s.order_of_key(idx2[a[i]]);
        s.insert(idx2[a[i]]);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
