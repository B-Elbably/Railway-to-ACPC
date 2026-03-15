#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {cin >> a[i]; ans += (a[i] == c);}
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++){
        if (a[i] == c) continue;
        pos[a[i]].push_back(i);
    }

    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + (a[i] == c ? 1 : 0);

    int res = 0;
    for (auto &[x, indices] : pos) {
        int mx = 0, last = 0;
        for (int idx: indices) {
            int sum = 1 - (pre[idx] - pre[last]);
            mx = max(1LL, mx + sum);
            res = max(res, mx);
            last = idx;
        }
    }
    ans += res;
    cout << ans << "\n";

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
