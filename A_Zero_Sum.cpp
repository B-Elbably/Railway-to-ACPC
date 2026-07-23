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
    int sum = 0;
    if (n == 2) {
        if (a[0] == a[1]) cout << "NO\n";
        else cout << "YES" << endl;
        return;
    }
    if (n & 1) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < n; i++) sum += (a[i] == -1);
    // cout << sum << " " << n/2 << endl;
    if ((abs(n / 2 + sum) & 1)) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
