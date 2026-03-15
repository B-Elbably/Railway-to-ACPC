#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MAXN = 2e5 + 5;
const int LOG = 19;

int succ[MAXN][LOG];
bool is_cycle[MAXN];
int cycle_len[MAXN];

int get_succ(int x, int k) {
    for (int p = 0; p < LOG; ++p) {
        if ((k >> p) & 1) {
            x = succ[x][p];
        }
    }
    return x;
}

int query(int x) {
    if (is_cycle[x]) return cycle_len[x];
    int dist = 0;
    int curr = x;
    for (int p = LOG - 1; p >= 0; --p) {
        if (!is_cycle[succ[curr][p]]) {
            curr = succ[curr][p];
            dist += (1 << p);
        }
    }
    return dist + 1 + cycle_len[succ[curr][0]];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        succ[i][0] = x - 1;
    }
    
    for (int i = 1; i < LOG; ++i) {
        for (int j = 0; j < n; ++j) {
            succ[j][i] = succ[succ[j][i - 1]][i - 1];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        int v = get_succ(i, n);
        if (is_cycle[v]) continue;
        
        int curr = succ[v][0];
        int len = 1;
        while (curr != v) {
            len++;
            curr = succ[curr][0];
        }
        
        is_cycle[v] = true;
        cycle_len[v] = len;
        curr = succ[v][0];
        while (curr != v) {
            is_cycle[curr] = true;
            cycle_len[curr] = len;
            curr = succ[curr][0];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << query(i) << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}