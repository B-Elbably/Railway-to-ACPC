#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    set<int> idx;
    for (int i = 0; i < n; i++) idx.insert(i);
    for (int i = 0; i < n; i++) {
        vector<int> x, y;
        for (int j = i; idx.count(j) && j < n; j += k) {
            x.push_back(a[j]);
            y.push_back(b[j]);
            idx.erase(j);
        }
        sort(all(x));
        sort(all(y));
        if (x != y) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
