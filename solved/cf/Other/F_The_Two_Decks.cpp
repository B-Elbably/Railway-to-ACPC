#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct twoSat {
    int n;
    vector<vector<int>> adj;
    vector<int> dfsTime, low, cmpID, stk;
    int curT, cmpCnt;
    vector<bool> assignment;

    twoSat(int nVariables) {
        n = nVariables;
        adj.resize(2 * n + 1);
        dfsTime.assign(2 * n + 1, -1);
        low.assign(2 * n + 1, -1);
        cmpID.assign(2 * n + 1, -1);
        assignment.assign(n + 1, false);
        curT = cmpCnt = 0;
    }

    int lit(int x) {
        return x < 0 ? -x + n : x;
    }

    int neg(int x) {
        return x <= n ? x + n : x - n;
    }

    void addOr(int u, int v) {
        u = lit(u);
        v = lit(v);
        adj[neg(u)].push_back(v);
        adj[neg(v)].push_back(u);
    }

    void addXor(int u, int v) {
        u = lit(u);
        v = lit(v);
        addOr(u, v);
        addOr(neg(u), neg(v));
    }

    void forceTrue(int u) {
        u = lit(u);
        adj[neg(u)].push_back(u);
    }

    void forceFalse(int u) {
        u = lit(u);
        adj[u].push_back(neg(u));
    }

    void addImplication(int u, int v) {
        u = lit(u);
        v = lit(v);
        adj[u].push_back(v);
        adj[neg(v)].push_back(neg(u));
    }

    void addEqual(int u, int v) {
        addImplication(u, v);
        addImplication(v, u);
    }

    void tarjanDfs(int u) {
        dfsTime[u] = low[u] = ++curT;
        stk.push_back(u);
        for (int v : adj[u]) {
            if (dfsTime[v] == -1) {
                tarjanDfs(v);
                low[u] = min(low[u], low[v]);
            } else if (cmpID[v] == -1) {
                low[u] = min(low[u], dfsTime[v]);
            }
        }
        if (low[u] == dfsTime[u]) {
            while (true) {
                int v = stk.back();
                stk.pop_back();
                cmpID[v] = cmpCnt;
                if (v == u) break;
            }
            cmpCnt++;
        }
    }

    bool solve() {
        for (int i = 1; i <= 2 * n; i++) {
            if (dfsTime[i] == -1) {
                tarjanDfs(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (cmpID[i] == cmpID[i + n]) return false;
            assignment[i] = cmpID[i] < cmpID[i + n];
        }
        return true;
    }
};
const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    // if (n % 2 || n * (n - 2) / 4 > m) {
    //     cout << "impossible\n";
    //     return;
    // }
    // int nn = n;
    n *= 2;
    vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, true));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = false;
    }
    twoSat solver(n);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!adj[i][j]) {
                solver.addXor(i, j);
            }
        }
    }
    if (!solver.solve()) {
        cout << "0\n";
        return;
    }
    map<int, vector<int>> t0, t1;
    for (int i = 1; i <= n; i++) {
        int id = min(solver.cmpID[i], solver.cmpID[i + n]);
        if (solver.cmpID[i] == id) {
            t0[id].push_back(i);
        } else {
            t1[id].push_back(i);
        }
    }
    vector<int> keys;
    for (auto& p : t0) {
        keys.push_back(p.first);
    }
    int comps = keys.size();
    vector<vector<int>> dp(comps + 1, vector<int>(n / 2 + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < comps; i++) {
        int w0 = t0[keys[i]].size();
        int w1 = t1[keys[i]].size();
        for (int j = 0; j <= n / 2; j++) {
            if (dp[i][j]) {
                if (j + w0 <= n / 2) dp[i + 1][j + w0] += dp[i][j];
                if (j + w1 <= n / 2) dp[i + 1][j + w1] += dp[i][j];
                if (j + w0 <= n / 2) dp[i + 1][j + w0] %= MOD;
                if (j + w1 <= n / 2) dp[i + 1][j + w1] %= MOD;
            }
        }
    }
    int inv2 = 5e8 + 4;
    cout << (dp[comps][n / 2] * inv2) % MOD;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}