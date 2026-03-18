#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(all(ans), a[i]);
        if (it == ans.end()) {
            ans.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }
    cout << ans.size() << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
