#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int ans = 0;
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
        if (s[i--] != t[j--]) break;
        ans++;
    }
    cout << n + m - 2 * ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
