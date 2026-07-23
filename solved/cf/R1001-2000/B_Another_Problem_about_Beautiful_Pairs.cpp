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
    int SQ = 450;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < SQ) continue;
        for (int j = i; j < n; j += a[i]) {
            ans += (a[i] * a[j] == j - i);
        }
    }
    for (int j = 0; j < n; j++) {
        for (int x = 1; x < SQ; x++) {
            int i = j - x * a[j];
            if (i < 0) break;
            ans += (i < j && a[i] == x);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
