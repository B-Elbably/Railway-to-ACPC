#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        pos[x] = i;
    }
    vector<int> idx(n + 1, n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        int l = min(pos[u], pos[v]);
        int r = max(pos[u], pos[v]);
        idx[l] = min(idx[l], r);
    }
    int ans = 0;
    int mx = n + 1;
    for (int i = n; i >= 1; --i) {
        mx = min(mx, idx[i]);
        ans += mx - i;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
