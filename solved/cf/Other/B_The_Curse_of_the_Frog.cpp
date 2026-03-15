#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, x;
    cin >> n >> x;
    int sum = 0, add = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sum += (b - 1) * a;
        add = max(add, a * b - c);
    }
    if (sum >= x) {
        cout << 0 << endl;
        return;
    }
    if (add == 0) {
        cout << -1 << endl;
        return;
    }
    cout << (x - sum + add - 1) / add << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
