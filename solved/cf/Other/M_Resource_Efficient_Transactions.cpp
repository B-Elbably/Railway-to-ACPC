#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int x, k;
    cin >> x >> k;
    // x = k * (c1 + c2) + c1
    int sum = (x + k) / (k + 1);
    int xx = k * sum;
    int c1 = x - sum * k;
    int c2 = sum - c1;
    if (c1 >= 0 && c2 >= 0) {
        cout << c1 << " " << c2 << endl;
        return;
    }
    cout << -1 << " " << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
