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
    sort(all(a) , greater<int>());
    int ans = 0, go = 0;
    for (int i = 0; i < n; ++i) {
        int now = a[i] * (i + 1);
        if (now >= ans) {ans = now; go = a[i];}
    };
    cout << ans << ' ' << go << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
