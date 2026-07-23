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

void solve() {
    int n, m;
    cin >> n >> m;
    twoSat solver(n);
    vector<pair<int, int>> neg;
    for (int i = 0; i < m; i++) {
        int o, u, v;
        cin >> o >> u >> v;
        if (o == 1) {
            solver.addOr(u, v);
        } else {
            solver.addOr(u + n, v + n);
            neg.push_back({u, v});
        }
    }
    if (solver.solve()) {
        for (auto [u, v]: neg) {
            if (solver.cmpID[u] == solver.cmpID[v + n]) {
                cout << "NO\n";
                return;
            }
            if (solver.cmpID[v] == solver.cmpID[u + n]) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            cout << solver.cmpID[i + n] - solver.cmpID[i] << " "; 
        }
        cout << endl;
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}