#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int freq[5];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) freq[i % 5]++;
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int x = (5 - (i % 5)) % 5;
        ans += freq[x];
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
