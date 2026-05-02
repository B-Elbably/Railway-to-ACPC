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
    for (int i = 0; i < n; i++) {
        cin >> a[i]; sum += a[i];
    } 
    vector<int> suf(n);
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = min(a[i], suf[i + 1]);
        sum -= suf[i];
    }
    sum -= a[n - 1];
    int mx = 0, last = -1, cnt;
    for (int i = 0; i < n; i++) {
        if (suf[i] != last) cnt = 1;
        else cnt++;
        last = suf[i];
        mx = max(mx, cnt);
    }
    cout << sum + mx - 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
