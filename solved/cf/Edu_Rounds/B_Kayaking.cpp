#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 1e9;
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            vector<int> b;
            for (int k = 0; k < n; ++k){
                if (k != i && k != j){
                    b.push_back(a[k]);
                }
            }
            sort(all(b));
            int res = 0;
            for (int k = 0; k < b.size(); k += 2) res += abs(b[k] - b[k + 1]);
            ans = min(ans, res);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
