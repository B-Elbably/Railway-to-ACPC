#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define int long long
#define endl '\n'

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), pos(n + 1);
    for (int i = 0; i < n; i++) { cin >> a[i]; pos[a[i]] = i; }
    
    vector<int> b(n), pos_b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        pos_b[i] = pos[b[i]];
    }
    Tree<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (s.size() - s.order_of_key(pos_b[i]));
        s.insert(pos_b[i]);
    }
    cout << ans << endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
