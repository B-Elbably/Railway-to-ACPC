#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        vector<int> pref(n);
        int mx = 0;
        for (int j = 0; j < n - 1; j++) {
            int idx = (i + j) % n;
            mx = max(mx, a[idx]);
            pref[(idx + 1) % n] = mx;
        }
        cout << "\npref: ";
        for (int &x : pref) cout << x << " ";
        cout << endl;
        mx = 0;
        vector<int> suf(n);
        for (int j = 1; j < n; j++) {
            int idx = (i - j + n) % n;
            // for (int &x : suf) cout << x << " ";
            mx = max(mx, a[idx]);
            suf[idx] = mx;
            sum += min(pref[idx], mx);
        }
        cout << "suf: ";
        for (int &x : suf) cout << x << " ";
        cout << endl;
        cout << sum << " ";
        sum = 0;
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
