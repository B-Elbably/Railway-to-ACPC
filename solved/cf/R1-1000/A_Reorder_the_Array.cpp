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
    sort(all(a));
    vector<int> b;
    for (int x: a) b.push_back(x);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (b.back() > a.back()) {ans++; b.pop_back();}
        a.pop_back();
    }
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
