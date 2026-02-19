#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 1e9 + 7;
const int MAXN = 300005;
#define l first
#define r second

pair<int, int> tree[MAXN];
int ans[MAXN]; 
void dfs1(int u) {
    if (u == 0) return;
    dfs1(tree[u].l);
    dfs1(tree[u].r);
    ans[u] = (ans[tree[u].l] + ans[tree[u].r] + 2) % MOD;
}

void dfs2(int u, int sum) {
    if (u == 0) return;    
    ans[u] = (sum + ans[u] - 1) % MOD;
    dfs2(tree[u].l, ans[u]);
    dfs2(tree[u].r, ans[u]);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> tree[i].l >> tree[i].r;
    dfs1(1);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t; 
    while (t--) solve();
    return 0;
}