#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
typedef long long ll;

const int MAX_N = 200005;
const int LOG = 20;

vector<int> adj[MAX_N];
int up[MAX_N][LOG];

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        up[u][i] = up[up[u][i - 1] ][i - 1];
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> near(n + 2, n + 1);
    stack<int> st;
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (!st.empty()) near[i] = st.top();
        st.push(i);
    }
    for (int i = 1; i <= n; i++) adj[near[i]].push_back(i);
    dfs(n + 1, n + 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 1;
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[l][i] <= r) {
                ans += (1LL << i);
                l = up[l][i];
            }
        }
        cout << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
