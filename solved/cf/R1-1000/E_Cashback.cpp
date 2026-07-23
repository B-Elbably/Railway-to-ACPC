#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n + 1), pref(n + 1), dp(n + 1);
    multiset<int> ms;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        dp[i] = dp[i - 1] + a[i];
        ms.insert(a[i]);
        if (ms.size() > c)
            ms.erase(ms.find(a[i - c]));
        if (i < c) continue;
        dp[i] = min(dp[i], dp[i - c] + 
                (pref[i] - pref[i - c]) - *ms.begin());
    }
    cout << dp[n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
