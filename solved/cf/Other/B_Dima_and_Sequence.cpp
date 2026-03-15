#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    for (auto &x : a) {
        cin >> x;
        freq[x]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        freq[a[i]]--;
        ans += freq[2 * a[i]];
        ans += freq[2 * a[i] + 1];
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
