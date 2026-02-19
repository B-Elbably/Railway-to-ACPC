#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n + 2, vector<int>(m + 2, LLONG_MAX));
    vector<pair<int, int>> tele ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == 'o') {
                tele.push_back({i, j});
            }
        }
    }
    int ans = (n + m - 2) * 2;
    sort(all(tele), [](const pair<int,int>& a, const pair<int,int>& b) {
        return (a.first + a.second) < (b.first + b.second);
    });

    if (tele.size() > 1) {
        auto [x1, y1] = tele.front();
        auto [x2, y2] = tele.back();
        x1 -= x2;
        y1 -= y2;
        ans = min(ans, (x1 + y1 + n + m - 2) * 2 + 1);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
