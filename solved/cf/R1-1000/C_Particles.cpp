#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> ev, od;
    int mx = -1e18;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mx = max(mx, x);
        if (i % 2 == 0) ev.push_back(x);
        else od.push_back(x);
    }
    
    if (mx <= 0) {
        cout << mx << '\n';
        return;
    }
    
    int sum_ev = 0, sum_od = 0;
    for (int x : ev) {
        if (x > 0) sum_ev += x;
    }
    for (int x : od) {
        if (x > 0) sum_od += x;
    }
    
    cout << max(sum_ev, sum_od) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}