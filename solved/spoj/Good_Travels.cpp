#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 1e6 + 5;
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
vector<int> nadj[N];
vector<int> sccSum;
int ans[N];
vector<bool> vis(N, false);
int s, e;

int dfs(int u) {
    int &ret = ans[u];
    if (ret != -1) return ret;
    ret = -4e18; 
    if (u == cmpID[e]) ret = 0;
    for (int v : nadj[u]) {
        ret = max(ret, dfs(v));
    }    
    if (ret != -4e18) ret += sccSum[u];
    return ret;
}

void solve() {
    cin >> n >> m >> s >> e;
    initGraph(n);
    vector<int> value(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    tarjan();
    sccSum.resize(cmpCnt);
    for (int i = 1; i <= n; i++) {
        sccSum[cmpID[i]] += value[i];
    }
    set<pair<int, int>> edges;
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (cmpID[u] == cmpID[v]) continue;
            edges.insert({cmpID[u], cmpID[v]});
        }
    }
    for (auto [u, v] : edges) {
        nadj[u].push_back(v);
    }
    // for (int s: sccSum) cout << s << " ";
    // cout << endl;
    memset(ans, -1, sizeof(ans));
    cout << dfs(cmpID[s]) << endl;
}
#undef int
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}