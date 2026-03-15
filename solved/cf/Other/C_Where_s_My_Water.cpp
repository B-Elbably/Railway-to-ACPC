#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> pref(n, 0), suff(n, 0);

    for (int i = 0; i < n; i++) {
        int mx = a[i], sum = 0;
        for (int x = i; x >= 0; x--) {
            mx = max(mx, a[x]);
            sum += h - mx;
        }
        mx = a[i];
        pref[i] = max(pref[i], sum);
        for (int j = i + 1; j < n; j++) {
            mx = max(mx, a[j]);
            sum += h - mx;
            pref[j] = max(pref[j], sum);
        }
    }

    for (int i = 0; i < n; i++) {
        int mx = a[i], sum = 0;
        for (int x = i; x < n; x++) {
            mx = max(mx, a[x]);
            sum += h - mx;
        }
        mx = a[i];
        suff[i] = max(suff[i], sum);
        for (int j = i - 1; j >= 0; j--) {
            mx = max(mx, a[j]);
            sum += h - mx;
            suff[j] = max(suff[j], sum);
        }
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, pref[i] + suff[i + 1]);
    }
    cout << max(ans, pref[n - 1]) << "\n";
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
