#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const int N = 1e6 + 5, MOD = 1e9 + 7;
vector<int> divs[N];
int dp[N];

void precompute() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divs[j].push_back(i);
        }
        reverse(all(divs[i]));
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int d: divs[a[i]]) {
            dp[d] = (dp[d] + dp[d - 1]) % MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    solve();
    return 0;
}