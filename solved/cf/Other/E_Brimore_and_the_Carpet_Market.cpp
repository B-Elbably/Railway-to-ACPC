#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> a(n);
    for (auto &x : a) cin >> x, mp[x]++;
    int ans = 0, add = 0;
    for (auto [x, y] : mp) {
        int sum = y * (y - 1) / 2;
        ans += sum * add;
        add += sum;
    }
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("brimore.in", "r", stdin);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
