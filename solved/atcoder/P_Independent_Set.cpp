#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int n;
vector<int> adj[N];
int memo[2][N];

int go(int u, int type, int p) {
    int &ret = memo[type][u];
    if (~ret) return ret;
    ret = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (type == 0) {
            int temp = (go(v, 0, u) + go(v, 1, u)) % MOD;
            ret = (ret * temp) % MOD;
        } else {
            ret = (ret * go(v, 0, u)) % MOD;
        }
    }
    return ret;
}

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v; --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(memo, -1, sizeof memo);
    cout << (go(0, 0, -1) + go(0, 1, -1)) % MOD << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
