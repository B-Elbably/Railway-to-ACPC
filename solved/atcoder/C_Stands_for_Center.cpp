#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s; cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'C') {
            ans += min(i + 1, n - i);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
