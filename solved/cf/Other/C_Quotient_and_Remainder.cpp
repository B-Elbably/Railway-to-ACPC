#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> q(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i] ;
    }
    for (int i = 0; i < n; ++i) {
        cin >> r[i] ;
    }
    sort(allr(q));
    sort(all(r));
    int ans = 0;
    int i = 0;
    for (int j = 0; j < n; ++j) {
        while (i < n && q[i] * (r[j] + 1) > k - r[j]) i++;
        if (i == n) break;
        ans++;
        i++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}