#include <bits/stdc++.h>
using namespace std;

int n, m;
int adj[18];
int dp[1 << 18];
bool clique[1 << 18];

int go(int mask) {
    if (mask == 0) return 0;
    if (clique[mask]) return 1;
    int &ret = dp[mask];
    if (~ret) return ret;
    
    ret = 1e9;
    for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
        if (clique[sub]) {
            ret = min(ret, 1 + go(mask ^ sub));
        }
    }
    return ret;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) adj[i] = (1 << i);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v; --u; --v;
        adj[u] |= (1 << v);
        adj[v] |= (1 << u);
    }
    
    for (int mask = 0; mask < (1 << n); ++mask) {
        clique[mask] = true;
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) && ((adj[i] & mask) != mask)) {
                clique[mask] = false;
                break;
            }
        }
    }
    
    memset(dp, -1, sizeof(dp));
    cout << go((1 << n) - 1) << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}