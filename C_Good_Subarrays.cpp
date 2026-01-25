#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    char x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i] = x - '0' - i;
    }
    map<int, int> count; count[0]++;
    int pref = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        pref += a[i];
        ans += count[pref - 1 + (i * (i - 1) / 2)]++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
