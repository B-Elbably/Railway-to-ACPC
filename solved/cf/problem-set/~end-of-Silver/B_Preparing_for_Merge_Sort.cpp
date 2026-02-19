#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<int>> ans;
    vector<int> ref;
    ans.push_back({a[0]});
    ref.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        int l = 0, r = ans.size();
        while (l < r) 
        {
            int mid = (l + r) / 2;
            if (ref[mid] > a[i]) l = mid + 1;
            else r = mid;
        }
        if (l == ans.size()) {
			ans.push_back({a[i]});
            ref.push_back(a[i]);
		} else {
			ans[l].push_back({a[i]});
            ref[l] = a[i];
		}
        
    }
    for (auto &v : ans) {
        for (auto &x : v) cout << x << ' ';
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
