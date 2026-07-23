#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n; double k;
    cin >> n >> k; 
    int mx = (int)ceil(n * k), cnt = 0;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 50) cnt++;
    }
    cout << (cnt >= mx ? "YES" : "NO") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
