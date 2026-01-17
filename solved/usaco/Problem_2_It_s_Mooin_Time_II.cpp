#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    map<int, pair<int, int>> mp;
    map<int, int> status;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (!status.count(a[i])) mp[a[i]].first = i;
        mp[a[i]].second++;
    }
    for (int i = n - 1; i >= 0; --i) {
        mp[a[i]].second--;
        if (mp[a[i]].second == 0) mp.erase(a[i]);
        if (!status.count(a[i])) { status[a[i]] = 1; continue;}
        if (status[a[i]] == 2) continue;
        ans += mp.size() - (mp.count(a[i]));
        status[a[i]] = 2;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
