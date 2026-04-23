#include <bits/stdc++.h>
using namespace std;


#define int unsigned long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n, m , k;
vector<int> a;
const int N = 21;
int dp[1 << N];
set<int> adj[N];
int ans = 0;
vector<int> pro;

void go(int i, int mask, int sum) {
    if (i == n) {
        ans++;
        return;
    }
    go(i + 1, mask, sum);
    int nw = mask | (1ULL << i);
    bool ok = true;
    for (int x : pro) {
        if ((x & nw) == x) {
            ok = false;
            break;
        }
    }
    if (sum + a[i] <= k && ok) {
        go(i + 1, nw, sum + a[i]);
    }
}

void solve() {
    cin >> n >> m >> k;
    a.resize(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < m; ++i){
        int l, r; cin >> l >> r;
        --l; --r;
        pro.push_back((1ULL << l) | (1ULL << r));
    }
    go(0, 0, 0);
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
