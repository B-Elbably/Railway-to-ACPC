#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        vector<bool> keep(n, true);
        for (int i = 0; i < mid; i++) keep[a[i] - 1] = false;
        int j = 0;
        for (int i = 0; i < n && j < t.size(); i++) {
            if (!keep[i]) continue;
            if (s[i] == t[j]) j++;
        }
        if (j == t.size()) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l - 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
