#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = n;
    gp_hash_table<int, null_type> go;
    for (int i = -1; i < n; ++i) {
        if (~i) {
            if (go.find(a[i]) != go.end()) {
                break;
            }
            go.insert(a[i]);
        }
        gp_hash_table<int, null_type> back = go;
        for (int j = n - 1; j > i; --j) {
            if (back.find(a[j]) != back.end()) {
                break;
            }
            back.insert(a[j]);
        }
        ans = min(ans, n - (int)back.size());
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
