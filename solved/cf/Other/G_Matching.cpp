#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i] - i].push_back(a[i]);
    }
    for (auto &p : mp) {
        vector<int> &vals = p.second;
        sort(all(vals));
        for (int i = vals.size() & 1; i < vals.size() - 1; i += 2) {
            ans += max(0LL, vals[i] + vals[i + 1]);
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
