#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
map<int, vector<int>> adj;
vector<bool> vis;

void dfs(int u) {
    vis[u] = true;
    for (auto &v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.first >> x.second;
    int l = 0, r = 2e9;
    while (l < r) {
        int mid = (l + r) / 2;
        adj.clear();
        vis.assign(n, false);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = (a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second);
                if (d <= mid) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        bool ok = 1;
        dfs(0);
        for (int i = 1; i < n; i++) {
            if (!vis[i]) {
                ok = 0;
                break;
            }
        }
        if (ok) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
