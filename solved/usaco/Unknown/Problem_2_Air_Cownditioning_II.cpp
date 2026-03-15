#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, t, c; 
    cin >> n >> m;

    vector<int> target(102, 0);
    for (int i = 0; i < n; i++) {
        cin >> s >> t >> c;
        target[s] += c; target[t + 1] -= c;
    }
    for (int i = 1; i <= 100; i++) target[i] += target[i - 1];

    vector<array<int, 4>> ac(m);
    for (int i = 0; i < m; i++) {
        cin >> ac[i][0] >> ac[i][1] >> ac[i][2] >> ac[i][3];
    }

    int ans = LLONG_MAX;
    for (int mask = 0; mask < (1 << m); mask++) {
        vector<int> cool(102, 0);
        int now = 0;

        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                auto [a, b, p, c] = ac[i];
                cool[a] += p;
                cool[b + 1] -= p;
                now += c;
            }
        }

        for (int i = 1; i <= 100; i++) cool[i] += cool[i - 1];

        bool ok = true;
        for (int i = 1; i <= 100; i++) {
            if (cool[i] < target[i]) {
                ok = false;
                break;
            }
        }

        if (ok) ans = min(ans, now);
    }

    cout << ans;
}
