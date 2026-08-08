#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (auto &x : a) cin >> x, sum ^= x;
    // cout << sum << endl;
    if (sum) {
        cout << 0 << endl;
    }else {
        cout << 1 << endl;
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
