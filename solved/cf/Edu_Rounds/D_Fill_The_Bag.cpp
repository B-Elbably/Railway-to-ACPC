#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    vector<int> free(62, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; sum += a[i];
        free[__builtin_ctzll(a[i])]++;
    }
    if (sum < k) {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    for (int i = 0; i < 60; ++i) {
        if (k & (1LL << i)) {
            if (free[i] > 0) {
                free[i]--;
            } else {
                int j = i + 1;
                while (j < 60 && free[j] == 0) {
                    j++;
                }
                free[j]--;
                for (int l = j - 1; l >= i; l--) {
                    free[l]++;
                    ans++;
                }
            }
        }
        free[i + 1] += free[i] / 2;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
