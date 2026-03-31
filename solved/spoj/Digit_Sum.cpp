#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

string s;
pair<int, int> memo[20][2];

pair<int, int> go(int i, bool tight) {
    if (i == s.size()) return {0, 1};
    pair<int, int> &ret = memo[i][tight];
    if (ret.first != -1) return ret;
    ret = {0, 0};
    int limit = tight ? (s[i] - '0') : 9;
    for (int d = 0; d <= limit; ++d) {
        pair<int, int> next = go(i + 1, tight && (d == limit));
        ret.first += next.first + (d * next.second);
        ret.second += next.second;
    }
    return ret;
}

int calc(int n) {
    if (n < 0) return 0;
    s = to_string(n);
    memset(memo, -1, sizeof(memo));
    return go(0, 1).first;
}

void solve() {
    int x1, x2;
    cin >> x1 >> x2;
    cout << calc(x2) - calc(x1 - 1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}