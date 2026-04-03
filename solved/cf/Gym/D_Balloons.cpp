#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    // set<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        // s.insert(x);
        ans +=  x > 0;
    }
    // s.erase(0);
    // cout << s.size() << endl;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
