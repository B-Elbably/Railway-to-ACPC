#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

vector<int> mp1(10, 0), mp2(10, 0);
int common(string &a, string &b) {
    for (int i = 0; i < 10; i++) {
        mp1[i] = mp2[i] = 0;
    }
    for (auto &x : a) mp1[x - '0']++;
    for (auto &x : b) mp2[x - '0']++;
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += min(mp1[i], mp2[i]);
    }
    return ans;
}

void solve() {
    int n, s, e;
    cin >> n >> s >> e;
    vector<string> a(n + 1);
    vector<int> dist(n + 1, LLONG_MAX);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int c = common(a[i], a[j]);
            if (c == 17) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    if (s == e) {
        cout << 0 << endl;
        return;
    }
    if (adj[s].empty() || adj[e].empty()) {
        cout << -1 << endl;
        return;
    }
    queue<pair<int, int>> q;
    q.push({s, 0});
    dist[s] = 0;
    while (!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        if (d > dist[u]) continue;
        if (u == e) break;
        for (int v : adj[u]) {
            if (dist[v] > d + 1) {
                dist[v] = d + 1;
                q.push({v, d + 1});
            }
        }
    }
    if (dist[e] == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << dist[e] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
