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
    vector<int> b = a;
    sort(all(b));
    int ans = 0;
    for (int i = 0; i < n; ++i){
        ans += (a[i] != b[i]);
    }
    cout << ans - 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}


// 2 4 7 7 9 3
// 2 3 4 7 7 9
