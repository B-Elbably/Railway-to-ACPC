#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k, go = 0;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    for (auto &x : a) {
        cin >> x; 
        mp[x]++;
    }
    sort(all(a));
    for (auto [key, weight] : mp) {
        go += weight * n;
        if (go >= k) {
            cout << key << " " << a[n - 1 - (go - k) / weight] << endl;
            return;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}