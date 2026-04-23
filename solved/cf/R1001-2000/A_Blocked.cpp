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
    int ok = 1;
    for (int i = 0; i < n - 1; ++i) ok &= (a[i] != a[i + 1]);
    if (!ok) {
        cout << "-1\n";
        return;
    }
    for (int i = n - 1; i >= 0; --i) cout << a[i] << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
