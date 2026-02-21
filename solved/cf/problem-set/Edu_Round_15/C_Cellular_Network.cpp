#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m + 2);
    for (auto &x : a) cin >> x;
    for (int i = 1; i <= m; i++) cin >> b[i];
    b[0] = -1e10;
    b[m + 1] = 1e10;
    vector<int> mins;
    int l = 1;
    for (int r = 0; r < n; r++) {
        while (!(a[r] >= b[l - 1] && a[r] < b[l])) l++;
        mins.push_back(min(a[r] - b[l - 1], b[l] - a[r]));
    }
    cout << *max_element(all(mins));
    // max(...mins)
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
