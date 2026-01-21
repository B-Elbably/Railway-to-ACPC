#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n, m;
const int N = 1e2 + 5;
int adj[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    vector<int> color(n + 1, 0);
    color[1] = 1;
    for (int i = 2; i <= n; ++i) {
        set<int> free = {1, 2, 3, 4};
        for (int j = 1; j <= n; ++j) {
            if (adj[i][j] && color[j] != 0) {
                free.erase(color[j]);
            }
        }
        color[i] = *free.begin();
    }
    for (int i = 1; i <= n; ++i) 
        cout << color[i];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
