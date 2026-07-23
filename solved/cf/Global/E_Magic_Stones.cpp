#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin() + 1, (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (int i = n - 2; i >= 0; --i) {
        a[i + 1] -= a[i];
        b[i + 1] -= b[i];
    }
    sort(all(a));
    sort(all(b));
    // for (int x: a) cout << x << " "; cout << endl;
    // for (int x: b) cout << x << " "; cout << endl;
    cout << (a == b ? "Yes" : "No") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
