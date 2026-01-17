#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m ;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    set<int> ans; int ac = b[0];
    for (int i = 0; i < n; ++i) {
        ac -= a[i];
        ans.insert(ac);
    }
    for (int i = 1; i < m; ++i) {
        set<int> res ; int  ac = b[i];
        for (int j = 0; j < n; ++j) {
            ac -= a[j];
            res.insert(ac);
        }
        set<int> tmp;
        set_intersection(ans.begin(), ans.end(), res.begin(), res.end(),
                    inserter(tmp, tmp.begin()));
        ans.swap(tmp);
    }
    cout << ans.size() << endl;
    // for (auto x : ans) cout << x << ' ';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
