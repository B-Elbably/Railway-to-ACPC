#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<char> a(n);
    map<char, int> mp;
    for (auto &x : a) cin >> x, mp[x]++;
    int ans = 0;
    for (auto &[x, y] : mp) ans += y / 2;
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
