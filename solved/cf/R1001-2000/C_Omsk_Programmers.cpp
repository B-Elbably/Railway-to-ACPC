#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int a, b, x;
    cin >> a >> b >> x;
    vector<int> op1, op2;
    int ans = abs(a - b);
    while (a) {
        op1.push_back(a);
        a /= x;
    }
    while (b) {
        op2.push_back(b);
        b /= x;
    }
    op1.push_back(0);
    op2.push_back(0);
    int n = op1.size();
    int m = op2.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = min(ans, i + j + abs(op1[i] - op2[j]));
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
