#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct edge {
    int u, v, w;
};

const int N = 1e5 + 5;
set<int> adj[N];

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    } return 1;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<edge> ans;
    ans.push_back({1, n, 2});
    adj[1].insert(n);
    adj[n].insert(1);
    int sum = 2;
    m--;
    for (int i = 2; i < n; ++i) {
        ans.push_back({1, i, 1});
        adj[1].insert(i);
        adj[i].insert(1);
        sum++;
        m--;
    }
    while (!is_prime(sum)){
        sum++;
        ans[ans.size() - 1].w++;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (m == 0) break;
            if (i == j) continue;
            if (adj[i].count(j)) continue;
            ans.push_back({i, j, n + n + 1});
            adj[i].insert(j);
            adj[j].insert(i);
            m--;
        }
        if (m == 0) break;
    }
    cout << 2 << " " << sum << "\n";
    for (edge x: ans) {
        cout << x.u << " " << x.v << " " << x.w << endl;
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
