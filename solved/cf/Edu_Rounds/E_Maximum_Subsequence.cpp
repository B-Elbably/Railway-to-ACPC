#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int k = n / 2;
    vector<int> left, right;
    for (int i = 0; i < (1 << k); i++) {
        int sum = 0;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) sum += a[j], sum %= m;
        }
        left.push_back(sum);
    }
    for (int i = 0; i < (1 << (n - k)); i++) {
        int sum = 0;
        for (int j = 0; j < n - k; j++) {
            if (i & (1 << j)) sum += a[k + j], sum %= m;
        }
        right.push_back(sum);
    }
    sort(all(right));
    int ans = 0;
    for (int x : left) {
        int need = (m - x - 1) % m;
        auto it = lower_bound(all(right), need);
        if (it != right.end()) ans = max(ans, (x + *it) % m);
        if (it != right.begin()) ans = max(ans, (x + *prev(it)) % m);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
