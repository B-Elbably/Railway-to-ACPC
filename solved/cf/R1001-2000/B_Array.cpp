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
    for (int i = 0; i < n; ++i) {
        int mx = 0, mn = 0;
        for (int j = i + 1; j < n; ++j) {
            mx += (a[j] > a[i]);
            mn += (a[j] < a[i]);
        }
        cout << max(mx, mn) << ' ';
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
