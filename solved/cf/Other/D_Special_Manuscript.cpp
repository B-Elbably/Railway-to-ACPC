#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0' - 1;
    }
    int ans = 0;
    map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans += mp[sum];
        mp[sum]++;
    }
    cout << (ans * 2 >= n ? "YES" : "NO") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
