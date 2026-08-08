#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]] = i + 1;
    }
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        double x1 = sqrt(x);
        double y1 = sqrt(y);
        double z1 = sqrt(z);
        double sum = x1 + y1 + z1;
        int l = llround(2.0L * sum / sqrtl(3.0L));
        int ok = 0;
        for (int i = -2; i <= 3; ++i) {
            int ans = l + i; 
            if (ans < 0) continue;
            double ll = sqrtl(3.0L) * ans / 2.0L;
            if (fabs(ll - sum) > 1e-8) continue;
            if (!mp.count(ans)) continue;
            ok = 1;
            cout << mp[ans] << endl;
            break;
        }
        if (!ok) cout << "-1\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
