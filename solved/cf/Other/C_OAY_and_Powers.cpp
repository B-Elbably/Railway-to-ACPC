#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;
    vector<int> ans;
    int ones = 1 & n;
    for (int i = 1; i <= 31; i++) {
        int now = 1 << i;
        // cout << "i: " << i << " now: " << now << "  n & now: " << (n & now) << endl;
        if (n & now) {
            ans.push_back(now);
        }
    }
    // for (int x: ans) cout << x << ' ';
    // cout << endl;
    // cout << ones << endl;

    while ((!ans.empty()) && (ones + ans.size() < k))
    {
        int now = ans.back();
        ans.pop_back();
        if (now == 2) {
            ones += 2;
        } else {
            ans.push_back(now / 2);
            ans.push_back(now / 2);
        }
    }
    if (ones + ans.size() != k) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (auto x : ans) {
            cout << x << ' ';
        }
        for (int i = 0; i < ones; i++) {
            cout << 1 << ' ';
        }
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
