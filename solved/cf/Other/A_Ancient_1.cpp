#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, p;
    cin >> n >> p;
    int l = 1, r = p;
    int ans = 0;
    if (p == 1) {
        cout << n + n - 1 << endl;
        return;
    }
    if (n <= p) {
        cout << n << endl;
        return;
    }
    while (l <= r) {
        int mid = (l + r) / 2;
        int res = 0;
        int cnt = mid;
        int start = n;
        int ok = 1;
        while (cnt <= p) {
            if (start - cnt < 1) {
                ok = 0;
                break;
            }
            res += start;
            start -= cnt++;
        }
        if (ok) {
            ans = max(ans, res + start);
            // res += start;
            r = mid - 1;
        }else {
            l = mid + 1;
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
