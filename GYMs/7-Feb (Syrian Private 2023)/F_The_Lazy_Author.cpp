#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i < n - k + 1; ++i) {
        while (!q.empty() && q.front() < i) q.pop();
        if ((a[i] & 1) == (q.size() & 1)) {
            if (i + k - 1 > n) break;
            ans.push_back(i);
            q.push(i + k - 1);
        }
    }
    int zeros = 0;
    for (int i = n - k + 1; i <= n; ++i) {
        while (!q.empty() && q.front() < i) q.pop();
        if ((a[i] & 1) == (q.size() & 1)) {
            zeros++;
        }
    }
    if (zeros > k / 2) ans.push_back(n - k + 1);
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
