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

    int zero = 0, one = 0, two = 0;
    for (int x : a) {
        if (x == 0) zero++;
        else if (x == 1) one++;
        else two++;
    }

    int ans = min(one, two);
    one -= ans;
    two -= ans;
    ans += one / 3;
    ans += two / 3;
    ans += zero;
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
