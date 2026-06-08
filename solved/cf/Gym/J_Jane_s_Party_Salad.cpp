#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'


void solve() {
    int n, k, f;
    cin >> n >> k >> f;
    vector<vector<int>> a(f);
    for (int i = 0; i < f; i++) {
        int m;
        cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int ans = 0;
    for (int i = 0; i < (1LL << f); i++) { 
        // if (__builtin_popcountll(i) < k) continue;
        vector<int> cnt(n, 0);
        for (int j = 0; j < f; j++) {
            if (i & (1LL << j)) {
                for (int x : a[j]) {
                    cnt[x] = 1;
                }
            }
        }
        int res = 0;
        for (int x : cnt) {
            if (x == 0) res++;
        }
        for (int j = 0; j < f; j++) {
            if (i & (1LL << j)) {
                for (int x : a[j]) {
                    cnt[x] = 0;
                }
            }
        }
        // cout << i << " " << res << endl;
        if (res >= k){
            ans = max(ans, (int)__builtin_popcountll(i));
        }
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
