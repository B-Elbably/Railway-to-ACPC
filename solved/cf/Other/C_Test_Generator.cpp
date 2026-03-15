#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

bool can(int n, int s, int m) {
    int sum = s;
    for (int i = 60; i >= 0; i--) {
        int val = 1LL << i;
        if (m & val) {
            sum -= min(n, sum / val) * val;
        }
    }
    return sum == 0;
}

void solve() {
    int s, m;
    cin >> s >> m;
    if (!can(s, s, m)) {
        cout << -1 << endl;
        return;
    }
    int l = 1, r = s, ans = s;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (can(mid, s, m)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t; 
    while (t--) solve();
}