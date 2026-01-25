#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(all(a), greater<int>());
    int j = n - 1, ans = 0;
    for (int i = 0; i < n && j >= i; i++) {
        if (a[i] + a[j] <= x) {
            ans++;
            j--;
        } else {
            ans++;
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
}
