#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MAXN = 1e3 + 5;
const int LOG = 10;

int succ[MAXN][LOG];
bool is_cycle[MAXN];

int get_succ(int x, int k) {
    for (int p = 0; p < LOG; ++p) {
        if ((k >> p) & 1) {
            x = succ[x][p];
        }
    }
    return x;
}

int query(int x) {
    if (is_cycle[x]) return x;
    for (int p = LOG - 1; p >= 0; --p) {
        if (!is_cycle[succ[x][p]]) {
            x = succ[x][p];
        }
    }
    return succ[x][0];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        succ[i][0] = x - 1;
    }
    
    for (int i = 1; i < LOG; ++i) {
        for (int j = 0; j < n; ++j) {
            succ[j][i] = succ[succ[j][i - 1]][i - 1];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        int v = get_succ(i, n);
        is_cycle[v] = true;
        int curr = succ[v][0];
        while (curr != v) {
            is_cycle[curr] = true;
            curr = succ[curr][0];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << query(i) + 1 << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}