#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

// 5 3 1 4 7 2 9 10 6 8

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &ai : a) cin >> ai;
    if (2 * x <= n) {
        cout << "YES\n";
        return;
    }
    vector<int> b = a;
    sort(all(b));
    for (int i = n - x; i < x; i++) {
        if (a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    // for (auto &x : ans) cout << x << " ";   
    // cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
