#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int INF = 1e15;
const int N = 2e5 + 5;
int dist[2][N];

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    for (int i = 0; i <= n + 1 ; ++i) {
        dist[0][i] = dist[1][i] = INF;
    }
    vector<vector<int>> adj(n + 1);
    int sum = 0;
    vector<int> odd;
    for (int i = 0; i < l; ++i) {
        int x; cin >> x;
        sum += x;
        if (x & 1) odd.push_back(x);
    }
    odd.push_back(sum * 2 + 1);
    sort(all(odd));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    while (!q.empty()) {
        auto [u, ev] = q.front();
        q.pop();
        for (int v: adj[u]) {
            int cost = dist[ev][u] + 1;
            if (dist[ev ^ 1][v] > cost) {
                dist[ev ^ 1][v] = cost;
                q.push({v, ev ^ 1});
            }
        }
    }
    vector<int> ans;
    int p = sum & 1;
    for(int i = 0; i < n; ++i){
        int op1 = dist[p][i];
        int op2 = dist[p ^ 1][i] + odd[0];
        int res = 1;
        if (min(op1, op2) > sum) res = 0;
        ans.push_back(res);
    }
    for (int x: ans) cout << x;
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
