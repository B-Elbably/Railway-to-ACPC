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
    int sum = 0;
    int bad = 0;
    int one = 0;
    int ok1 = 0, ok2 = 0;
    for (int i = 0; i < n; i++) {
        one += a[i];
        if (a[i] != b[i]) {
            bad++;
            sum += a[i];
            continue;
        }
        ok1 |= (a[i] == 1);
        ok2 |= (a[i] == 0);
    }
    if (!bad) {
        cout << 0 << endl;
        return;
    }
    if (!one) {
        cout << -1 << endl;
        return;
    }
    if (sum & 1) {
        cout << 1 << endl;
    }else if (sum >= 2) {
        cout << 2 << endl;
    }else if (ok1 && ok2) {
        cout << 2 << endl;
    }else {
        cout << -1 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
