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
const int N = 2e6 + 5;
int spf[N];
void sieve() {
    for (int i = 1; i < N; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<vector<int>> primeFactors(N);
void factorize(int n, int i) {
    while (n > 1) {
        int p = spf[n];
        primeFactors[p].push_back(i);
        while (n % p == 0) n /= p;
    }   
}

void solve() {
    int n;
    cin >> n;
    twoSat solver(1e6);
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        factorize(a, i);
        factorize(b, -i);
    }
    
    int vars = n;
    for (int p = 2; p < N; p++) {
        if (primeFactors[p].empty()) continue;
        solver.addImplication(primeFactors[p][0], ++vars);
        if (primeFactors[p].size() == 1) continue;
        for (int i = 1; i < primeFactors[p].size(); i++) {
            solver.addImplication(vars - 1, -primeFactors[p][i]);
            solver.addImplication(primeFactors[p][i], ++vars);
            solver.addImplication(vars - 1, vars);
        }
    }
    
    cout << (solver.solve() ? "Yes" : "No") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int t = 1;
    while (t--) solve();
    return 0;
}