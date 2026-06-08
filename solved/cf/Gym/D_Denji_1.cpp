#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define endl '\n'

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    ordered_set s;
    for (int i = 1; i <= n; i++) {
        int type; cin >> type;
        if (type == 1) {
            int x; cin >> x;
            mp[i] = x;
            s.insert({x, i});
        } else if (type == 2) {
            int idx; cin >> idx;
            s.erase({mp[idx], idx});
            mp.erase(idx);
        } else if (type == 3) {
            // int x, idx; cin >> x >> idx;
            int idx, x; cin >> idx >> x;
            s.erase({mp[idx], idx});
            mp[idx] += x;
            s.insert({mp[idx], idx});
        } else if (type == 4) {
            int idx; cin >> idx;
            cout << s.order_of_key({mp[idx], idx}) << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}