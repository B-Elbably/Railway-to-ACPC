#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int x = a + b + c - 3;
    vector<int> v = {a, b, c};
    sort(all(v));
    int y = max(0LL, v[2] - v[0] - v[1] - 1);
    cout << ((x >= m && m >= y) ? "YES" : "NO") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
