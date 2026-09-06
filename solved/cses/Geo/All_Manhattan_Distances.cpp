#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void print(__int128_t x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    string s;
    while (x > 0) {
        s += (x % 10) + '0';
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    sort(all(a));
    sort(all(b));

    __int128_t ans = 0;
    vector<int> pref1(n + 1, 0), pref2(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref1[i + 1] = pref1[i] + a[i];
        pref2[i + 1] = pref2[i] + b[i];
    }
    for (int i = 0; i < n; i++) {
        __int128_t o1 = a[i] * i - pref1[i];
        __int128_t o2 = b[i] * i - pref2[i];
        // ans += a[i] * i - pref1[i];
        // ans += b[i] * i - pref2[i];
        ans += o1 + o2;
    }
    print(ans);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
