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
    sort(all(a));
    if (a[0] != 1) {
        cout << 1 << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        sum += a[i];
        if (sum + 1 < a[i + 1]) {
            cout << sum + 1 << endl;
            return;
        }
    }
    sum += a[n - 1];
    cout << sum + 1 << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
