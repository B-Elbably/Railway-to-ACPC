#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

pair<int, int> parse(int t) {
    if (t < 0) t += 24 * 60;
    int h = t / 60;
    int m = t % 60;
    return {h, m};
}

bool check(int t) {
    auto [h, m] = parse(t);
    string s = to_string(h) + to_string(m);
    for (char c : s) {
        if (c == '7') return true;
    }
    return false; 
}

void solve() {
    int x, h, m;
    cin >> x >> h >> m;
    int t = h * 60 + m;
    int ans = 0;
    while (1) {
        if (check(t)) break;
        t -= x;
        ans++;
    }
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
