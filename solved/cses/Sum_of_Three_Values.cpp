#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(all(a));
    for (int m = 1; m < n - 1; ++m) {
        int l = 0, r = n - 1;
        while (l < m && r > m) {
            int sum = a[l].first + a[m].first + a[r].first;
            if (sum == k) {
                cout << a[l].second << " " << a[m].second << " " << a[r].second << endl;
                return;
            }
            else if (sum < k) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;   
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
