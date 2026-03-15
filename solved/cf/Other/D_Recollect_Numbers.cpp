#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    if (k < n || k >= 2 * n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    k -= n - 1;
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(1 + (k != 1));
    for (int i = 1; i < k - 1; i++) {
        ans.push_back(i);
        ans.push_back(i + 2);
    }
    if (k > 1) {
        ans.push_back(k - 1);
        ans.push_back(k);
    }
    for (int i = k + 1; i <= n; i++) {
        ans.push_back(i);
        ans.push_back(i);
    }
    for (int x : ans) cout << x << ' ';
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}


