#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 998244353;
const int N = 5e3 + 5;
vector<int> adj[N];
int vis[N];

int fast_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            vis[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            int j = a[a[i]] + k;
            if (j > n) continue;
            adj[a[i]].push_back(j);
        }
        int cycles = 0;
        for (int i = 1; i <= n; ++i) {
            int u = i;
            if (vis[u]) continue;
            int add = 1;
            while (!vis[u]) {
                vis[u] = 1;
                if (adj[u].empty()) {add = 0; break;}
                u = adj[u][0];
            }
            if (u == i) cycles += add;
        }
        ans += fast_pow(2, cycles) - 1;
        if (ans > MOD) ans -= MOD;
        if (ans < 0) ans += MOD;
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
