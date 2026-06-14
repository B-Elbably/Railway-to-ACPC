#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + m);
    for (auto &x : a) cin >> x;
    vector<int> taxi, person;
    vector<int> ans(m);
    for (int i = 0; i < n + m; ++i) {
        int x; cin >> x;
        if (x == 1) taxi.push_back(a[i]);
        else person.push_back(a[i]);
    }
    taxi.push_back((a[n + m - 1]) * 3);
    int i = 0;
    for (int p: person) {
        int low = upper_bound(all(taxi), p) - taxi.begin();
        int idx = -1, dist = LLONG_MAX;
        int mn = max(0LL, low - 1);
        int mx = min(low + 1, m);
        for (int j = mn; j < mx; ++j) {
            int d = abs(taxi[j] - p);
            if (d < dist) {
                dist = d;
                idx = j;
            }
        }
        ans[idx]++;
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << " ";
    }
}

// taxi: 2 4 6 10
// pers: 15

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
