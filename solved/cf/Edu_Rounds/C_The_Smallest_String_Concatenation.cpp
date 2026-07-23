#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    sort(all(a), [](const string &x, const string &y) {
        return x + y < y + x;
    });
    for (auto &x : a) cout << x;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
