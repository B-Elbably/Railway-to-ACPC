#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int s, ans;
int n;
vector<int> a(2);
void go(int i, int mx, int sum) {
    if (sum <= s) {
        ans = min(ans, s - sum);
    }
    if (sum > s) {
        ans = min(ans, sum - s);
        return;
    }
    if (i == mx) {
        if (sum >= s) ans = min(ans, sum - s);
        else ans = min(ans, s - sum);
        return;
    }
    go(i + 1, mx, sum * 10 + a[0]);
    go(i + 1, mx, sum * 10 + a[1]);
}

void solve() {
    cin >> s >> n;
    cin >> a[0] >> a[1];
    ans = ULLONG_MAX;
    int mx = 0;
    int nn = s;
    while (nn) {
        nn /= 10;
        mx++;
    }
    mx = min(mx, 18ULL);
    mx = max(mx, 1ULL);
    for (int i = max(1ULL, mx - 1); i <= min(mx + 1, 18ULL); i++) {
        go(0, i, 0);
    }
    // string ss(size == mx + 1)
    string ss(mx + 1, to_string(a[0])[0]);
    ss[0] = to_string(a[1])[0];
    int s_ = stoull(ss);
    if (s_ >= s)
        ans = min(ans, s_ - s);
    string ss2(mx + 1, to_string(a[1])[0]);
    ss2[0] = to_string(a[0])[0];
    s_ = stoull(ss2);
    if (s_ >= s) ans = min(ans, s_ - s);
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
