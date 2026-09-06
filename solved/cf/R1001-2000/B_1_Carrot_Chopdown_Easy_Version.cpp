#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> freq(2 * m + 1, 0);
    for (auto &x : a) cin >> x, freq[x]++;
    for (int i = 1; i <= 2 * m; ++i) freq[i] += freq[i - 1];
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int sum = freq[m] - freq[i - 1] + freq[i * 2] - freq[i * 2 - 1];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
