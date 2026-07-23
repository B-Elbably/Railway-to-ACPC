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
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i - 1];
    int sum = 0;
    // for (int x: pref) cout << x << " ";
    vector<int> ans;
    int l = 0, r = n;
    for (int i = 0; i < n; ++i) {
        sum += pref[r] - pref[l];
        // cout << "pref " << pre
        ans.push_back(sum);
        l++; r--;
    }
    for (int x: ans) cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
