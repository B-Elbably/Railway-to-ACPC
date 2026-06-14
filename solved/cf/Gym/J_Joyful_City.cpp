#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 3e5 + 5;
int deg[N];
int b[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++; deg[v]++;
    }
    
    int ans = n * b[0];
    vector<int> gains;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < deg[i]; k++) {
            gains.push_back(b[k + 1] - b[k]);
        }
    }
    
    sort(gains.rbegin(), gains.rend());
    for (int i = 0; i < n - 1; i++) {
        ans += gains[i];
    }
    
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}