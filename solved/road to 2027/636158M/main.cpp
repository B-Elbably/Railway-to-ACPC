#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, vector<int>> mp1, mp2;
    for (int i = 0; i < n; ++i) {
        mp1[i & 1].push_back(a[i]);
    }
    sort(all(a));
    for (int i = 0; i < n; ++i) {
        mp2[i & 1].push_back(a[i]);
    }
    sort(all(mp1[0]));
    sort(all(mp1[1]));
    sort(all(mp2[0]));
    sort(all(mp2[1]));
    if (mp1 == mp2) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
