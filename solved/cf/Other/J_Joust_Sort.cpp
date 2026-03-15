#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 26;
vector<vector<int>> adj(N, vector<int>(N));
vector<int> vis(N, 0); 
vector<int> order;
bool iscycle = false;

void topo(int u) {
    vis[u] = 1; 
    for (int v = 0; v < N; v++) {
        if (adj[u][v]) {
            if (vis[v] == 1) {
                iscycle = true;
                return;
            }
            if (vis[v] == 0) topo(v);
        }
    }
    vis[u] = 2;
    order.push_back(u);
}

void solve() {
    int n;
    cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        char a, op, b;
        cin >> a >> op >> b;  
        int u = a - 'a',  v = b - 'a';
        if (op == '>')
            adj[u][v] = 1;
        else
            adj[v][u] = 1;
    }
    string s;
    cin >> s;
    for (char c : s) freq[c - 'a']++;

    for (int i = 0; i < N; i++) {
        if (vis[i] == 0)
            topo(i);
    }
    if (iscycle) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (int u : order) {
        for (int j = 0; j < freq[u]; j++)
            cout << char(u + 'a');
        freq[u] = 0;
    }
    for (auto &p : freq) {
        for (int i = 0; i < p.second; i++)
            cout << char(p.first + 'a');
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}