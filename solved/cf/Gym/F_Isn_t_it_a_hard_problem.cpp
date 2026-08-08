#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cost(n), add(n);
    int ans = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < ((int)s.size() / 2); ++j) {
            cost[i] += (s[j] != s[(int)s.size() - j - 1]);
        }
    }
    for (int &x: add) cin >> x;
    int sum = 0, w = 0;
    deque<int> dq;

    for (int i = 0; i < n; ++i) {
        if (cost[i] > k) {
            dq.clear();
            sum = 0; w = 0;
            continue;
        }
        while (w + cost[i] > k) {
            int idx = dq.front(); dq.pop_front();
            w -= cost[idx];
            sum -= add[idx];
            ans = max(sum, ans);
        }
        sum += add[i];
        w += cost[i];
        dq.push_back(i);
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
