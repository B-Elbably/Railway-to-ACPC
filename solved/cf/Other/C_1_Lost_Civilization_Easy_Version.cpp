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
    int mn = a[0], mx = a[0];
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > mn && a[i] <= mx + 1) {
            mx = a[i];
        } else {
            ans++;
            mn = a[i];
            mx = a[i];
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