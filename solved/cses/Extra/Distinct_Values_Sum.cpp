#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> freq;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (freq.find(a[i]) == freq.end()) {
            freq[a[i]] = {-1};
        }
        freq[a[i]].push_back(i);
    }
    for (auto &[x, v] : freq) {
        v.push_back(n);
    }
    int ans = 0;
    for (auto &[x, v] : freq) {
        for (int i = 1; i < v.size(); ++i) {
            ans += (v[i] - v[i - 1]) * (n - v[i]);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
