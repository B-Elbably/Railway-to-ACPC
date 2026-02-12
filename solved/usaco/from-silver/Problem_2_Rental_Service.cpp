#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> cows(n), rent(r);
    vector<pair<int, int>> stores(m);
    for (auto &x : cows) cin >> x;
    for (auto &x : stores) cin >> x.second >> x.first; // p , q
    for (auto &x : rent) cin >> x;
    sort(all(cows), greater<int>());
    sort(all(rent), greater<int>());
    sort(all(stores), greater<pair<int, int>>());
    vector<int> milk(n+1, 0);

    int j = 0;
    for (int i = 0; i < n; ++i) {
        int milk_now = cows[i];
        int profit = milk[i];
        while (j < m && milk_now) {
            int take = min(milk_now, stores[j].second);
            profit += take * stores[j].first;
            milk_now -= take;
            stores[j].second -= take;
            if (stores[j].second == 0) j++;
        }
        milk[i + 1] = profit;
    }

    vector<int> rent_pref(n+1, 0);

    for (int i = 1; i <= min(n, r); ++i)
        rent_pref[i] = rent_pref[i-1] + rent[i-1];

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, milk[i] + rent_pref[min(n - i, r)]);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
