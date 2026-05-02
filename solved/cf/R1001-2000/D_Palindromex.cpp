#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    n <<= 1;
    vector<int> a(n);
    int lx = -1, rx = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            rx = i;
            if (~lx)continue;
            lx = i;
        }
    }
    int ans = 1;
    vector<vector<int>> idxx;
    idxx.push_back({lx, lx});
    idxx.push_back({rx, rx});
    // idxx.push_back({lx, rx});
    idxx.push_back({(lx + rx) / 2, (lx + rx) / 2});
    idxx.push_back({(lx + rx + 1) / 2, (lx + rx + 1) / 2});
    idxx.push_back({(lx + rx) / 2, (lx + rx + 1) / 2});
    for (int i = 0; i < idxx.size(); i++) {
        int l = idxx[i][0], r = idxx[i][1];
        while (l >= 0 && r < n && a[l] == a[r]) {
            l--; 
            r++;
        }
        vector<bool> seen(n / 2 + 1, false);
        for (int i = l + 1; i <= r - 1; i++) {
            if (a[i] * 2 <= n) seen[a[i]] = true;
        }
        for (int i = 0; i <= n / 2; i++) {
            if (!seen[i]) {
                ans = max(ans, i);
                break;
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
