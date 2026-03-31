#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i < 2 * n - 1; i++) {
        int x = a[2 * n - 1] + a[i];
        multiset<int> ms(a.begin(), a.end());
        vector<pair<int, int>> ans;
        for (int j = 0; j < n; j++) {
            int mx = *ms.rbegin();
            ms.erase(ms.find(mx));
            int target = x - mx;
            auto it = ms.find(target);
            if (it == ms.end()) break;

            ans.push_back({mx, target});
            x = mx;
            ms.erase(it);
        }

        if (ans.size() == n) {
            cout << "YES\n" << a[2 * n - 1] + a[i] << "\n";
            for (auto p : ans) cout << p.first << " " << p.second << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}


/*
    2 3 4 5 6 7 11 14 

    1 3
    2 4
*/
