#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<set<int>> a(n);
    set<int> aaa;
    for (auto &x : a) {
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int y;
            cin >> y;
            x.insert(y);
            aaa.insert(y);
        }
    }
    int ans = 0;
    for (int i: aaa) {
        set<int> s;
        for (int j = 0; j < n; ++j) {
            if (a[j].count(i)) continue;
            for (int k: a[j]) s.insert(k);
        }
        ans = max(ans, (int)s.size());
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
