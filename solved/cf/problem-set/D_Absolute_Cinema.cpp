#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum = (a[0] + a[n - 1]) / (n - 1);

    cout << (a[1] - a[0] + sum) / 2 << " ";
    for (int i = 1; i < n - 1; i++) {
        cout << (a[i + 1] - 2 * a[i] + a[i - 1]) / 2 << " ";
    }
    cout << (sum - a[n - 1] + a[n - 2]) / 2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
