#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    vector<bool> seen(n + 1);

    if(a[n - 1] == b[n - 1]) {
        cout << n << endl;
        return;
    }

    int ans = 0;
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] == b[i] || a[i] == a[i + 1] || b[i] == b[i + 1] ||
            seen[a[i]] || seen[b[i]]) {
            ans = i + 1;
            break;
        }
        seen[a[i + 1]] = seen[b[i + 1]] = true;
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
