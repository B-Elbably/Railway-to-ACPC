#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(all(a));
    sort(all(b));
    vector<int> freq(m, 0);
    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < m && b[j] < a[i] && (a[i] - b[j] > t)) j++;
        while(j < m && freq[j] == k) j++;
        if (j == m) break;
        // cout << i << " " << j << " ";
        if (abs(a[i] - b[j]) <= t) {
            freq[j]++; ans++;
            // cout << "1* " << ans << endl;
            continue;
        }
        if ((j + 1 >= m) || (b[j] > a[i])) continue;
        j++;
        if (abs(a[i] - b[j]) <= t) {
            freq[j]++; ans++;
            // cout << "2* " << ans << endl;
            continue;
        }
        // cout << "3* bad\n";
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
