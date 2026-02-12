#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> status;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        status[a[i]] = i & 1;
    }
    sort(all(a));
    int now = status[a[0]] ^ 1; 
    for (int i = 1; i < n; ++i) {
        if (status[a[i]] != now) {
            cout << "NO" << endl;
            return;
        }
        now ^= 1;
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
