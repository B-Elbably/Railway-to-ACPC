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
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> b(n, vector<int>(n));
    char c;
    vector<int> magic(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            b[i][j] = c - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> c;
        magic[i] = c - '0';
    }
    twoSat solver(n * 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int d = a[i][j] ^ b[i][j];
            if (magic[j] == 0 && magic[i] == 0) {
                if (d == 1) {
                    cout << "-1" << endl;
                    return;
                }
            } else if (magic[j] == 1 && magic[i] == 0) {
                if (d == 1) solver.forceTrue(i + 1);
                else solver.forceFalse(i + 1);
            } else if (magic[j] == 0 && magic[i] == 1) {
                if (d == 1) solver.forceTrue(n + j + 1);
                else solver.forceFalse(n + j + 1);
            } else {
                if (d == 1) solver.addXor(i + 1, n + j + 1);
                else solver.addEqual(i + 1, n + j + 1);
            }
        }
    }
    if (!solver.solve()) {
        cout << "-1" << endl;
        return;
    }
    vector<int> rowFlips, colFlips;
    for (int i = 1; i <= n; i++) {
        if (solver.assignment[i]) rowFlips.push_back(i - 1);
        if (solver.assignment[n + i]) colFlips.push_back(i - 1);
    }
    cout << rowFlips.size() + colFlips.size() << endl;
    for (int x : rowFlips) cout << "row " << x << endl;
    for (int x : colFlips) cout << "col " << x << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}