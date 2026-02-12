#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int sum;
vector<int> sums;

void calc() {
    auto it = lower_bound(all(sums), -sum);
    int ans = 1e15;
    if (it != sums.end()) ans = min(ans, abs(sum + *it));
    if (it != sums.begin()) ans = min(ans, abs(sum + *(--it)));
    cout << ans << endl;
}

void solve() {
    int n, m, q; sum = 0;
    cin >> n >> m >> q;
    vector<int> a(n + 1), b(m + 1), pref(m + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) sum += i & 1 ? a[i] : -a[i];
    for (int i = 1; i <= m; i++) pref[i] = pref[i - 1] + (i & 1 ? -b[i] : b[i]);
    for (int l = 0; l <= m - n; ++l) {
        int sum = pref[l + n] - pref[l] ;
        sums.push_back((l & 1) == 0 ? sum : -sum);
    }
    sort(all(sums)); calc();
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        if ((r - l + 1) & 1) sum += ((l & 1) ? x : -x);
        calc();
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
