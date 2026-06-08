#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n, k, x, a, b, c;

int f(int xi) {
    return (a * xi + b) % c;
}

void solve() {
    cin >> n >> k >> x;
    cin >> a >> b >> c;
    vector<int> a(n); 
    a[0] = x;
    for (int i = 1; i < n; i++) {
        a[i] = f(a[i - 1]);
    }
    // for (int i = 0; i < n; ++i) cout << a[i] << " ";
    vector<int> sums;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum ^= a[i];
        if (i >= k - 1) {
            sums.push_back(sum);
            sum ^= a[i - k + 1];
        }
    }
    int ans = 0;
    for (int s : sums) ans ^= s;
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
