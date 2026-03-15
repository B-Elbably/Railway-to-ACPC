#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        pos[x] = i;
    }
    
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (pos[i] < pos[i - 1]) {
            ans++;
        }
    }
    
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}