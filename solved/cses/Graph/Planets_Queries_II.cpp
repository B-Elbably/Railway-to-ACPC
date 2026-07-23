#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int LOG = 20;
const int N = 2e5 + 5;
int up[LOG][N];
int in[N], dep[N], compId[N], pos[N], compSize[N];

void build(int n) {
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }   
}

int kth(int u, int k) {
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            u = up[i][u];
        }
    }
    return u;
}

void solve() {
    int n, qq;
    cin >> n >> qq;
    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
        cin >> up[0][i];
        in[up[0][i]]++;
    }
    build(n);
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        if (--in[up[0][u]] == 0) q.push(up[0][u]);
    }
    int comp = 0;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) continue;
        comp++;
        int u = i, sz = 0;
        do {
            in[u] = 0;
            compId[u] = comp;
            pos[u] = sz++;
            u = up[0][u];   
        } while (u != i);
        compSize[comp] = sz;
    }
    for (int x: topo) cout << x << " "; cout << endl;
    for (int i = topo.size() - 1; i >= 0; i--) {
        int u = topo[i];
        int v = up[0][u];
        dep[u] = dep[v] + 1;
        compId[u] = compId[v];
    }
    while (qq--) {
        int a, b; 
        cin >> a >> b;
        if (compId[a] != compId[b]) {
            cout << -1 << endl;
            continue;
        }
        if (dep[a] < dep[b]) {
            cout << -1 << endl;
            continue;
        }
        int ans = dep[a] - dep[b];
        int c = kth(a, ans);
        if (c == b) {
            cout << ans << endl;
        } else if (dep[b] == 0){
            int add = (pos[b] - pos[c] + compSize[compId[a]]) % compSize[compId[a]];
            cout << ans + add << endl;
        } else {
            cout << -1 << endl;
        }
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
