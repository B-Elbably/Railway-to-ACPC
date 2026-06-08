#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    if (n <= 5) {
        cout << -1 << "\n";
        return;
    }
    vector<int> a(n, 0);
    a[0] = 1;
    if (n <= 8) {
        a[1] = 1; a[n / 2] = 1;
    } else {
        a[2] = a[5] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
