#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
struct person {
    string city, skill, val, type;
    int p, r, m;
};

void solve() {
    int n;
    cin >> n;
    vector<person> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].city >> a[i].skill >> a[i].val >> a[i].type;
        cin >> a[i].p >> a[i].r >> a[i].m;
    }
    int ans = -1;
    for (int  i = 1; i < n; ++i) {
        if (a[i].city != a[0].city) continue;
        if (a[i].skill == a[0].skill) continue;
        if (a[i].val != a[0].val) continue;
        ans = max(ans, 1000 * (a[i].type != a[0].type) +
        (a[i].p * a[0].p) + (a[i].r * a[0].r) + (a[i].m * a[0].m));
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
