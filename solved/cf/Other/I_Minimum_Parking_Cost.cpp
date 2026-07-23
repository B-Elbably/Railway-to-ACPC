#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<double> a(n);
    vector<double> p(n);
    for (auto &x : a) cin >> x;
    for (auto &x : p) cin >> x;
    double nxt = 0;
    for (int i = (int)5e7; i >= 0; --i) {
        double cur = p[i % n] * min(a[i % n], 1 + nxt);
        cur += (1 - p[i % n]) * (1 + nxt);
        nxt = cur;
    }
    cout << nxt << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
