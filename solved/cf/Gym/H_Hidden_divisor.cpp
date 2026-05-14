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
    sort(all(a));
    set<int> prob;
    if (n == 1) {
        if (a[0] == 1) cout << "*";
        else cout << a[0] << " " << 1;
        return;
    }
    for (int i = 0; i < min(n, 4LL); ++i) {
        for (int j = n - 1; j > max(0LL, n - 4); --j) {
            prob.insert(a[j]);
            prob.insert(a[j] * a[i]);
        }
    }
    set<int> aa(all(a));
    for (int x: prob) {
        // cout << "Trying " << x << endl;
        int cnt = 0;
        int ans = 0;
        for (int y: aa) {
            if (x % y == 0) {
                cnt++;
                if (!aa.count(x / y)) {
                    ans = x / y;
                }
            }
        }
        if (cnt == n) {
            if (ans == 0) {
                ans = sqrt(x);
                while ((ans + 1) * (ans + 1) <= x) ans++;
                while (ans * ans > x) ans--;
            }
            if (x % ans) continue;
            if (!aa.count(ans)) {
                cout << x << " " << ans;
                return;
            }
        }
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
