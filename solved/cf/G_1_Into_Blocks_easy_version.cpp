#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> last, cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        last[a[i]] = i; cnt[a[i]]++;
    }
    int ans = n;
    for (int i = 0; i < n; ++i) {
        int mx = cnt[a[i]];
        int pos = last[a[i]];
        for (int j = i + 1; j <= pos; ++j) {
            pos = max(pos, last[a[j]]);
            mx = max(mx, cnt[a[j]]);
        }
        ans -= mx;
        i = pos;
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
