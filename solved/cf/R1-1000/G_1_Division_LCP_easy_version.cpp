#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 2e5 + 15;
int Z[N];

void z_function(const string& s) {
    int n = s.length();
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            Z[i] = min(r - i + 1, Z[i - l]);
        else Z[i] = 0;
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
            ++Z[i];
        if (i + Z[i] - 1 > r)
            l = i, r = i + Z[i] - 1;
    }
}

void solve() {
    int n, l, r;
    string s;
    cin >> n >> l >> r >> s;
    if (l == 1) {
        cout << n << endl;
        return;
    }
    z_function(s);
    int ans = 0;
    int lx = 1, rx = n / l;
    while (lx <= rx) {
        int mid = lx + (rx - lx) / 2;
        int cnt = 0, last = 0;
        for (int i = mid; i < n; i++) {
            if (Z[i] >= mid) {
                cnt++;
                i += mid - 1;
            }
        }
        if (++cnt >= l) {
            ans = mid;
            lx = mid + 1;
        } else {
            rx = mid - 1;
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
