#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(all(a));
    sort(all(b));
    vector<int> prob(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            prob[i] += (a[i] <= b[j]);
        }
    }
    int ans = 1;
    for (int i = 0 ; i < n; ++i) {
        ans *= (prob[i] + i - n + 1);
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