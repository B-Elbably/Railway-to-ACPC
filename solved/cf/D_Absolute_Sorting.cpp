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
    int l = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (abs(a[i] - l) <= abs(a[i + 1] - l)) continue;
        int y = (a[i] + a[i + 1] + 1) / 2;
        if (y < l) {
            cout << -1 << endl;
            return;
        }
        l = max(l, y);
    }
    for (int i = 0; i < n; ++i) a[i] = abs(a[i] - l);
    if (!is_sorted(all(a))) l = -1;
    cout << l << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}


