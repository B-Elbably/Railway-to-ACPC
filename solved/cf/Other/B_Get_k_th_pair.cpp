#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(all(a));
    sort(all(b));
    int l = 0, r = 2e9 + 5;
    while (l < r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upper_bound(all(b), mid - a[i]) - b.begin();
        }
        if (cnt >= k) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
