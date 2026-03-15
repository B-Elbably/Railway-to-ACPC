#include <bits/stdc++.h>
using namespace std;

#define int long long

bool check(int x, int n, int m, int l, const vector<int>& a) {
    if (x < 0) return false;
    
    // The last interval is an absolute bottleneck
    if (l - a[n - 1] > x) return false;

    int total_danger = 0;
    int prev_t = 0;

    for (int i = 0; i < n; i++) {
        total_danger += (a[i] - prev_t);
        
        // If total danger exceeds what m animatronics can hold at level x
        if (total_danger > m * x) return false;

        // You flash the highest one. The adversary ensures the highest 
        // is as small as possible. The most they can "cram" into the 
        // other (m-1) animatronics is (m-1)*x.
        // Therefore, the one you flash is at least:
        int flash_val = max(0LL, total_danger - (m - 1) * x);
        
        total_danger -= flash_val;
        prev_t = a[i];
    }

    total_danger += (l - prev_t);
    return total_danger <= m * x;
}

void solve() {
    int n, m, l;
    if (!(cin >> n >> m >> l)) return;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int low = 0, high = l, ans = l;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, n, m, l, a)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}