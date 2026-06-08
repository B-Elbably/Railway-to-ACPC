#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 2e5 + 5;
vector<int> adj[N];
int dfsTime[N], low[N], cmpID[N];
int stk[N], sz;
int curT, cmpCnt;
int n, m;
vector<vector<int>> SCCs;

void initGraph(int nNodes) {
    n = nNodes;
    SCCs.clear();
    curT = sz = cmpCnt = 0;
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        dfsTime[i] = low[i] = cmpID[i] = -1;
    }
}

void tarjanDfs(int u) {
    dfsTime[u] = low[u] = ++curT;
    stk[sz++] = u;
    for (int v : adj[u]) {
        if (dfsTime[v] == -1) {
            tarjanDfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (cmpID[v] == -1) {
            low[u] = min(low[u], dfsTime[v]);
        }
    }
    if (low[u] == dfsTime[u]) {
        vector<int> comp;
        while (true) {
            int v = stk[--sz];
            cmpID[v] = cmpCnt;
            comp.push_back(v);
            if (v == u) break;
        }
        SCCs.push_back(comp);
        cmpCnt++;
    }
}

void tarjan() {
    for (int i = 1; i <= n; i++) {
        if (dfsTime[i] == -1) {
            tarjanDfs(i);
        }
    }
}

void solve() {
    cin >> n >> m;
    initGraph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    tarjan();
    cout << cmpCnt << endl;
    for (int i = 1; i <= n; i++) {
        cout << cmpID[i] + 1 << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}