#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    vector<int> ans(n + 1, LLONG_MAX);
    for (int i = 1; i <= n; i++)
        if (cnt[i]) ans[i] = 1;

    for (int i = 1; i <= n; i++) {
        if (ans[i] == LLONG_MAX) continue;
        for (int j = 2; i * j <= n; j++) {
            if (ans[j] == LLONG_MAX) continue;
            ans[i * j] = min(ans[i * j], ans[i] + ans[j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i] == LLONG_MAX) ans[i] = -1;
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
