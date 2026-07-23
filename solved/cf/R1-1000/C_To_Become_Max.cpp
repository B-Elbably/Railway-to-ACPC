#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int l = *max_element(all(a)), r = 1e9;
    while (l <= r) {
        int m = (l + r) / 2;
        int ok = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            int mx = m;
            int ok2 = 0;
            for (int j = i; j < n; ++j) {
                if (a[j] >= mx) {
                    ok2 = 1;
                    break;
                }
                if (j == n - 1) break;
                cnt += (mx - a[j]);
                mx--;
            }
            if (ok2 && cnt <= k) {
                ok = 1;
                break;
            }
        }
        if (!ok) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << r << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}