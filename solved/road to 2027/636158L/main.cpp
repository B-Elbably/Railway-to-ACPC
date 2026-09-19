#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    int sz = 101;
    for (auto &x : a) cin >> x, reverse(all(x)), sz = min(sz, (int)x.size());
    vector<char> b;
    for (int i = 0; i < sz; ++i) {
        char target = a[0][i];
        bool ok = true;
        for (int j = 1; j < n; ++j) {
            if (a[j][i] != target) {
                ok = false;
                break;
            }
        }
        if (ok) b.push_back(target);
        else break;
    }
    reverse(all(b));
    if (b.empty()) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for (auto &x : b) cout << x;
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
