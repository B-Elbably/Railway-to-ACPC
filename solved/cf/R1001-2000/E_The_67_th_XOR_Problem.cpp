#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).rbegin(), (x).rend()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0, mask = 0;
    for (int i = 29; i >= 0; --i) {
        mask |= (1LL << i);
        set<int> s;
        for (int j = 0; j < n; ++j) {
            s.insert(a[j] & mask);
        }
        int target = ans | (1LL << i);
        bool ok = false;
        for (int x : s) {
            if (s.count(target ^ x)) {
                ok = true;
                break;
            }
        }
        if (ok) ans = target;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}