#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<int,int>> v;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back({x, 0});
    }

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        v.push_back({x, 1});
    }
    sort(all(v));
    n *= 3; m *= 3;
    int bestDiff = n - m;
    int ans1 = n;
    int ans2 = m;
    for (auto &[dist, team] : v) {
        n -= (team == 0);
        m -= (team == 1);
        int diff = n - m;
        if (diff > bestDiff) {
            bestDiff = diff;
            ans1 = n;
            ans2 = m;
        }
    }
    cout << ans1 << ":" << ans2 << '\n';
}
