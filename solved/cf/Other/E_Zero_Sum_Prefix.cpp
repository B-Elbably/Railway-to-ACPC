#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (auto &x : a) {cin >> x; sum += x;}
    if (sum == 0) {
        cout << "NO" << endl;
        return;
    }
    sort(allr(a));
    cout << "YES" << endl;
    sum = 0; int j = 1;
    for (int i = 0; i < n; ++i) {
        while (sum + a[i] == 0) {
            swap(a[i], a[j++]);
        }
        sum += a[i];
        j = max(j, i + 1);
    }
    for (auto x : a) cout << x << ' ';
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
