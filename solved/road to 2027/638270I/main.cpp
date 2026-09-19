#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> mp;
    int i = 0;
    int ans = 0;
    int last = -1;
    for (int j = 0; j < n; ++j) {
        mp[a[j]]++;
        if (a[j]) last = a[j];
        int sum = (a[j] ? mp[a[j]] : mp[last]) + mp[0];
        // cout << i << " " << j << " -> ";
        while (i < j && sum != j - i + 1) {
            // cout << " i: " << i << ", j: " << j << ", last: " << last;
            mp[a[i]]--;
            sum = (a[j] ? mp[a[j]] : mp[last]) + mp[0];
            i++;
        }
        // cout <<
        ans = max(ans, j - i + 1);
        // cout << endl;
        // cout << endl;
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
