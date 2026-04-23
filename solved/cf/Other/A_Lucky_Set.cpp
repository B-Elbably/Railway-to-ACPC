#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int dx[] = {1, 2, 4, 7, 9};
void solve() {
    int n;
    cin >> n;
    int xx = 4;
    if (n < 5) xx = n;
    int ans = n / 11 * 5;
    n %= 11;
    for (int i : dx) {
        ans += n >= i;
    }
    cout << max(ans, xx) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
// 1 2 4 7 9
