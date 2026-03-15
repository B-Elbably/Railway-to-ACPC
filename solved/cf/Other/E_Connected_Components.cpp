#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    unordered_set<int> not_vis;
    for (int i = 1; i <= n; i++) not_vis.insert(i);
    vector<int> ans;
    while (!not_vis.empty()) {
        int start = *not_vis.begin();
        queue<int> q; q.push(start);
        not_vis.erase(start);
        int sz = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            vector<int> neighbors;
            for (int v : not_vis) {
                if (!adj[u].count(v)) neighbors.push_back(v);
            }
            for (int v : neighbors) {
                q.push(v);
                not_vis.erase(v);
                sz++;
            }
        }
        ans.push_back(sz);
    }

    sort(all(ans));
    cout << ans.size() << endl;
    for (int sz : ans) cout << sz << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}