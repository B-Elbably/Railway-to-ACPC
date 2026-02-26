#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m;
    cin >> n >> m;
    string ans = "Bob";
    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &y : b) cin >> y;
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    vector<int> freq(n + m + 1, 0);
    for (int x : a) {
        for (int j = x; j <= n + m; j += x) {
            freq[j]++;
        }
    }
    int one = 0, two = 0;
    int mx = (m + 1) / 2;
    for (int y : b) {
        one += (freq[y] == a.size());
        two += (freq[y] == 0);
        if (two > mx) break;
    }
    if (one > two - (m & 1)) ans = "Alice";
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
}