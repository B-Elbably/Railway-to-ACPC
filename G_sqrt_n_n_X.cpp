#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int x; cin >> x;
    int sq = sqrt(abs(x)) + 100;
    set <int> ans;

    for (int k = -sq; k <= sq; ++k) {
        if ((x - k * k) % (2 * k - 1)) continue;
        ans.insert((x - k * k) / (2 * k - 1));
    }
    cout << ans.size() << '\n';
    for (auto x: ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
