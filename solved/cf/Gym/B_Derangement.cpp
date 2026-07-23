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
    vector<int> b;
    for (int i = 1; i <= n; ++i) {
        if (a[i - 1] == i) b.push_back(i);
    }
    if (b.size() == 1) {
        cout << 1 << endl;
        cout << b[0] << " " << (1 + (b[0] == 1)) << endl;
        return;
    }
    cout << (b.size() + 1) / 2 << endl;
    for (int i = 0; i < b.size(); i += 2) {
        cout << b[i] << " " << b[(i + 1) % b.size()] << endl;
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
