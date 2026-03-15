#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, k = 1;
    cin >> n >> k;

    ordered_set a;
    for (int i = 1; i <= n; i++) a.insert(i);

    int pos = 0;
    while (!a.empty()) {
        pos = (pos + k) % a.size();
        auto it = a.find_by_order(pos);
        cout << *it << " ";
        a.erase(it);
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}