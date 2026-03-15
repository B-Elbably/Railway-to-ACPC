#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> freq(101);
        int sm = 0;
        for (int j = i; j < n; ++j) {
            sm += a[j];
            freq[a[j]]++;
            int avg = sm / (j - i + 1);
            if (avg * (j - i + 1) != sm) continue;
            if (freq[avg] == 0) continue;
            // cout << i << " " << j << endl;
            res += freq[avg] > 0;
        }
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
