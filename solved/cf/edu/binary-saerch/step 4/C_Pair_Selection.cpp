#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define endl '\n'
vector<pair<int, int>> a;

bool can(double x, int n, int k) {
    vector<double> weights(n);
    for (int i = 0; i < n; i++)
        weights[i] = (double)a[i].first - x * a[i].second;
    sort(allr(weights));
    double sum = 0;
    for (int i = 0; i < k; i++) sum += weights[i];
    return sum >= 0;
}

void solve() {
    int n, k;
    cin >> n >> k; a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    double l = 0, r = 1e6; 
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0;
        if (can(mid, n, k)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(10) << l << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}