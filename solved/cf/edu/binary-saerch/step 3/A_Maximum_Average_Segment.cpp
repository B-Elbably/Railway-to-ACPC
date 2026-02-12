#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n, d;
vector<int> a(1e5 + 1);
int resL, resR;

bool check(double x) {
    vector<double> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + (a[i] - x);

    double mn = 0; int idx = 0;
    for (int i = d; i <= n; i++) {
        if (pref[i - d] < mn) idx = i - d;
        mn = min(mn, pref[i - d]);
    
        if (pref[i] >= mn) {
            resL = idx + 1; resR = i;
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    double l = 0, r = 100;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << resL << " " << resR << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
