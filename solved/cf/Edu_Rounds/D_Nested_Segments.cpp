#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }

    sort(a.begin(), a.end(), [](const array<int, 3>& x, const array<int, 3>& y) {
        if (x[0] == y[0]) return x[1] > y[1];
        return x[0] < y[0];
    });

    vector<int> contains(n);
    // vector<int> contained(n);
    ordered_set s1;
    // ordered_set s2;

    for (int i = n - 1; i >= 0; i--) {
        contains[a[i][2]] = s1.order_of_key({a[i][1], n + 1});
        s1.insert({a[i][1], i});
    }

    // for (int i = 0; i < n; i++) {
    //     contained[a[i][2]] = i - s2.order_of_key({a[i][1], -1});
    //     s2.insert({a[i][1], i});
    // }

    for (int i = 0; i < n; i++) cout << contains[i] << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}