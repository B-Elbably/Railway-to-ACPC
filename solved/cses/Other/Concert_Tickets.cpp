#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        auto it = a.upper_bound(x);
        if (it == a.begin()) {
            cout << -1 << endl;
        } else {
            it--;
            cout << *it << endl;
            a.erase(it);
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
