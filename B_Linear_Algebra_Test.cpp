#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    vector<pair<int, int>> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        mp[a[i].first]++;
    }
    for (int i = 0; i < n; i++) {
        ans += mp[a[i].second];
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
