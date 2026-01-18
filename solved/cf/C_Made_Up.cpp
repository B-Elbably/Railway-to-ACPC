#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    int x;
    map<int, int> mp_a, mp_c;
    map<int , vector<int>> mp_b;
    for (int i = 0; i < n; ++i) {cin >> x; mp_a[x]++; }
    for (int i = 0; i < n; ++i){ cin >> x; mp_b[x].push_back(i + 1);}
    for (int i = 0; i < n; ++i) {cin >> x; mp_c[x]++;}
    // A[i] = B[C[i]]?

    int ans = 0;
    for (auto [ka, va]: mp_a) {
        for (int idx: mp_b[ka]) {
            ans += va * mp_c[idx];
        }
    }
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
