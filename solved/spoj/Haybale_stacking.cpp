#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin() + 1, (x).end() - 2
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2, 0);
    for (int i = 1; i <= k; ++i) {
        int l , r;
        cin >> l >> r;
        a[l]++; a[r + 1]--;
    }
    for (int i = 1; i <= n; ++i) {
        a[i] += a[i - 1];
    }
    sort(all(a));
    cout << a[n / 2] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
