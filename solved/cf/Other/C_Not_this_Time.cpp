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
    vector<int> b = a;
    set<int> s;
    int mn = LLONG_MAX, idx = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] < mn) {
            mn = a[i];
            idx = i;
        }
        s.insert(a[i]);
    }
    if (s.size() == 1) {
        cout << 0 << endl;
        return;
    }
    if (s.count(1)) {
        cout << -1 << endl;
        return;
    }
    vector<pair<int, int>> ops;
    bool ok = true;
    for (;ok;) {
        ok = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] == mn) continue;
            while (a[i] > mn) { 
                ok = true;
                a[i] = (a[i] + mn - 1) / mn;
                ops.emplace_back(i + 1, idx + 1);
            }
            if (a[i] < mn) {
                mn = a[i];
                idx = i;
                i = 0;
            }
            if (mn == 1) {
                cout << -1 << endl;
                return;
            }
        }
    }
    // for (int i : a) cout << i << " ";
    cout << endl;
    cout << ops.size() << endl;
    for (auto &p : ops) 
        cout << p.first << " " << p.second << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
