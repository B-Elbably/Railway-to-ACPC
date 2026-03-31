#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n,k ;
    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        set<int> s; for (int j = 0; j <= k; ++j) s.insert(j);
        while (x) {
            s.erase(x % 10);
            x /= 10;
        }
        if (s.empty()) ans++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
