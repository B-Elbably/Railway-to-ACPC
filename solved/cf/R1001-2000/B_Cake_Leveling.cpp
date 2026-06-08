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
    int last = 2e18;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        cout << min(last, sum / (i + 1)) << ' ';
        last = min(last, sum / (i + 1));
    }
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
