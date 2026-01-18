#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 2e5 + 5;
vector<int> removed(N);

void solve() {
   
    int n, m , k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    map<int, set<int>> die; // die step , idices
    for (int i = 0; i < n; ++i) {cin >> a[i]; removed[i] = 0;}
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(all(b));
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(all(b), a[i]) - b.begin() - 1;
        if (pos >= 0) die[b[pos] - a[i]].insert(i);
        if (pos + 1 < m) die[b[pos + 1] - a[i]].insert(i);
    }
    // for (auto [k, v] : die) {
    //     cout << k << " : ";
    //     for (auto x : v) cout << x << " ";
    //     cout << endl;
    // }
    string s; cin >> s;
    int ans = n;
    int steps = 0;
    for (char x : s) {
        steps += (x == 'R' ? 1 : -1);

        if (die.count(steps)) {
            int killed = 0;
            for (int idx : die[steps]) {
                killed += removed[idx] ^ 1;
                removed[idx] = 1;
            }
            ans -= killed;
            die[steps].clear();
        }

        cout << ans << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
  