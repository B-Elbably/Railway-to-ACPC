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
    int gc = a[0];
    for (int i = 1; i < n; ++i) gc = gcd(gc, a[i]);
    if (((a[n - 1] / gc) - n ) & 1) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
