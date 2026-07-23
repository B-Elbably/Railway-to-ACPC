#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int g = gcd(a, b);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] %= g;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 1; i < n; i++)
        ans = max(ans, v[i] - v[i - 1]);
    cout << min(g - ans, v.back() - v[0]) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
