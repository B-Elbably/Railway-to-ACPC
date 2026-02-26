#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, h, k;
    cin >> n >> h >> k;
    vector<int> a(n);
    int sum = 0;
    for (int &x : a) {
        cin >> x; sum += x;
    }
    int rounds = (h - 1) / sum;
    h-=  rounds * sum;
    int ans = rounds * (n + k) + n;

    vector<int> pref_min(n), suf(n);
    pref_min[0] = a[0];
    for (int i = 1; i < n; i++) 
        pref_min[i] = min(pref_min[i - 1], a[i]);

    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) 
        suf[i] = max(suf[i + 1], a[i]);

    int now = 0;
    for (int i = 0; i < n - 1; i++) {
        now += a[i];
        int best = max(now, now - pref_min[i] + suf[i + 1]);
        if (best >= h) {
            ans -= (n - (i + 1));
            break;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}