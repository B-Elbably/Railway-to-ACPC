#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> freq;
    int ans = 0, sum = 0;
    for (auto &x : a) cin >> x;
    freq[0] = 1;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans += freq[sum - k];
        freq[sum]++;
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
