#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 300005;
vector<int> adj[N];
int deg[N];
int dp[N][26];
vector<int> order;

void solve() {
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq; 
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            pq.push(i);
            dp[i][s[i - 1] - 'a'] = 1;
        }
    }

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        order.push_back(s[u - 1]);
        for (int v : adj[u]) {
            int ok = s[v - 1] - 'a';
            for (int c = 0; c < 26; c++) {
                dp[v][c] = max(dp[v][c], dp[u][c] + (ok == c));
            }
            deg[v]--;
            if (deg[v] == 0) pq.push(v);
        }   
    }

    if (order.size() < n) {
        cout << -1 << endl;
    } else {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int c = 0; c < 26; c++) {
                res = max(res, dp[i][c]);
            }
        }
        cout << res << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}