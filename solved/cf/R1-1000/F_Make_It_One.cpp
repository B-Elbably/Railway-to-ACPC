#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 3e5 + 5;

int freq[N + 1], cnt[N + 1];
__int128 dp[8][N];

__int128 nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    if (r == 0) return 1;
    __int128 res = 1;
    r = min(r, n - r);
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x, freq[x]++;
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            cnt[i] += freq[j];
        }
    }
    for (int k = 1; k <= 7; ++k) {
        for (int i = N - 1; i > 0; --i) {
            dp[k][i] = nCr(cnt[i], k);
            for (int j = i * 2; j < N; j += i) {
                dp[k][i] -= dp[k][j];
            }
        }
        if (dp[k][1] > 0) {
            cout << k << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
