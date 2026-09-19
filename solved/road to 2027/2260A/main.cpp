#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int zeros = 0;
    for (auto &x : a) cin >> x, zeros += (x == 0);
    if (zeros < 2) {
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    cnt += (a[0] == 0);
    cnt += (a[n - 1] == 0);
    cout << 2 - cnt << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
