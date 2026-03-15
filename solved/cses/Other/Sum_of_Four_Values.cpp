#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(all(a));
    for (int i = 0; i < n - 2; i++) {
        int target = x - a[i].first;
        for (int m = i + 2; m < n - 1; m++) {
            int l = i + 1, r = n - 1;
            while (l < m && r > m) {
                int sum = a[l].first + a[m].first + a[r].first;
                if (sum == target) {
                    cout << a[i].second << " " << a[l].second << " ";
                    cout << a[m].second << " " << a[r].second << endl;
                    return;
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
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
