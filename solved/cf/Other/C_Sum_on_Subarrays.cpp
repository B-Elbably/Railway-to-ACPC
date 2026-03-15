#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin() + 1, (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, -1);
    int mx = n;
    while (k) {
        int now = min(mx, k);
        a[now] = mx;
        k -= now;
        mx = now - 1;
    }
    reverse(all(a));
    mx = -1;
    for (int i = n; i >= 1; --i) {
        mx = max(mx, a[i]);
        if (a[i] == -1) a[i] = -mx;
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
