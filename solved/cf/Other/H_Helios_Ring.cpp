#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char mn = s[0];
    int idx = 0;
    // int bad = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] > s[i + 1]) {
            idx = i + 1;
            break;
        }
    }
    int ans = min(idx, n - idx);
    string t = s;
    sort(all(t));
    s = s.substr(idx, n) + s.substr(0, idx);
    
    if (s == t) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
