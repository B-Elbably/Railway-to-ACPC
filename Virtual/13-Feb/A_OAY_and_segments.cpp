#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
vector<pair<int, int>> a(n);
bool check(int k) {
    int left = 0;
    int right = 0;
    for (int i = 0; i < n; ++i) {
        left = max(left - k, a[i].first);
        right = min(right + k, a[i].second);
        if (left > right) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    a.assign(n, {0, 0});
    for (auto &x : a) cin >> x.first >> x.second;
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t; 
    while (t--) solve();
}
