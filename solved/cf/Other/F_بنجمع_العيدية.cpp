#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int i = 0, j = k - 1;
    multiset<int> s;
    int sum = 0;
    for (int x = 0; x < k; x++) {
        s.insert(a[x]);
        sum += a[x];
    }
    int ans = sum - *s.begin();
    while (j < n - 1) {
        sum -= a[i];
        s.erase(s.find(a[i]));
        i++; j++;
        sum += a[j];
        s.insert(a[j]);
        ans = max(ans, sum - *s.begin());
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
