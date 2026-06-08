#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    vector<int> ans(n + 1);
    for (auto &x : a) cin >> x;
    sort(all(a));
    for (int i = 1; i <= n; ++i) {
        for (int x: a) {
            if (x > i) break;
            if (!ans[i - x]) {
                ans[i] = 1;
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << (ans[i] == 1 ? "W" : "L");
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
