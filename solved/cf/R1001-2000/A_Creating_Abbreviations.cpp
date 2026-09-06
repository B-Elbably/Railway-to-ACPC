#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;
    vector<string> a(n);
    set<char> mp;
    for (auto &x : a) cin >> x;
    for (const auto &s : a) {
        mp.insert(toupper(s[0]));
    }
    int ok = 1;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        for (auto c: s) {
            if (mp.find(c) == mp.end()) {
                ok = 0;
                break;
            }
        }
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
