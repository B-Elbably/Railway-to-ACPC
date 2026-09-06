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
    vector<int> a(n + 1);
    twoSat ts(n);
    int ok = 1;
    vector<int> bad(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == -1) continue;
        if (a[i] == 0) {
            ts.forceTrue(i);
            continue;
        }
        set<int> s;
        int l = max(1LL, i - a[i] + 1);
        int r = min(n, i + a[i] - 1);
        bad[l]++;
        bad[r + 1]--;
        if (i - a[i] >= 1) s.insert(i - a[i]);
        if (i + a[i] <= n) s.insert(i + a[i]);
        if (s.size() == 0) {
            ok = 0;
        } else if (s.size() == 1) {
            ts.forceFalse(i);
            ts.forceTrue(*s.begin());
        
        } else {
            ts.forceFalse(i);
            ts.addOr(*s.begin(), *next(s.begin()));
        }
    }
    for (int i = 1; i <= n; ++i) {
        bad[i] += bad[i - 1];
        if (bad[i]) ts.forceFalse(i);
    }
    if (!ok || !ts.solve()) {
        cout << "-1" << endl;
        return;
    }
    vector<int> dist(n + 1, n + 2);
    
    for (int i = 1; i <= n; ++i) {
        if (ts.assignment[i]) dist[i] = 0;
    }
    for (int i = 2; i <= n; ++i) {
        dist[i] = min(dist[i], dist[i - 1] + 1);
    }
    for (int i = n - 1; i >= 1; --i) {
        dist[i] = min(dist[i], dist[i + 1] + 1);
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) continue;
        if (dist[i] != a[i]) {
            cout << "-1" << endl;
            return;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (ts.assignment[i]) cout << "1";
        else cout << "0";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}