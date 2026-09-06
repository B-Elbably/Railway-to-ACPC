#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n;
vector<int> a, b;
const int N = 2e5 + 5;
int dp[N];

int dfs(int i) {
    if (i == -1) return 0;
    int &ret = dp[i];
    if (~ret) return ret;
    return ret = dfs(b[i]) + (b[i] == -1 || a[b[i]] > a[i]);
}

void solve() {
    cin >> n;
    a.resize(n), b.resize(n);
    for (auto &x : a) cin >> x;
    
    memset(dp, -1, sizeof(dp));

    stack<int> s;
    for (int i = 0; i < n; ++i) {
        int last = -1;
        while (!s.empty() && a[s.top()] < a[i]) {
            last = s.top();
            s.pop();
        }
        if (s.empty()) {
            b[i] = -1;
        } else {
            b[i] = s.top();
        }
        if (last != -1){
            b[last] = i;
        }
        s.push(i);
    }
    // for (int i = 0; i < n; ++i) {
    //     cout << a[i] << " -> " << a[b[i]] << endl;

    // }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dfs(i));
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