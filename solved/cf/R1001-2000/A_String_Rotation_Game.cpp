#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int brute(const string &s) {
    int blocks = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] != s[i - 1]) blocks++;
    }
    return blocks;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    string t = s;
    for (int i = 0; i < n; i++) {
        ans = max(ans, brute(t));
        t = t.back() + t.substr(0, n - 1);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}