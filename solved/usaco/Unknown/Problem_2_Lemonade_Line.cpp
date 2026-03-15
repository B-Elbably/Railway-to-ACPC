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
    reverse(all(a));
    int i = 0; 
    for (; i < n; ++i) {
        if (a[i] < i) break;
    }
    cout << i << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
