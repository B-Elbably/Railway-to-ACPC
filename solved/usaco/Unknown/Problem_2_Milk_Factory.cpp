#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    vector<int> out(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        out[u]++;
    }

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (out[i] == 0) {
            if (ans != -1) {
                cout << -1 << endl;
                return;
            }
            ans = i;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    solve();
}
