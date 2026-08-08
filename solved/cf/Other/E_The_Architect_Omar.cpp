#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    map<char, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s[0]]++;
    }
    int ans = min({mp['k'], mp['l'], mp['b'] / 2});
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
