#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int go = 0;
    for (auto &x : a) {
        cin >> x;
        go += x;
    }
    sort(all(a));
    if (2 * a[n - 1] > go) {
        cout << 2 * a[n - 1] << endl;
    } else {
        cout << go << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}