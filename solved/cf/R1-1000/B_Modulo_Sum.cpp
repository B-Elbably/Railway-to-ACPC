#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    set<int> freq;
    if (n > m) {
        cout << "YES\n";
        return;
    }
    for (auto &x : a) {
        cin >> x; x %= m;
        set<int> temp = freq;
        for (auto y : temp) {
            freq.insert((x + y) % m);
        }
        freq.insert(x);
    }
    cout << (freq.count(0) == 1 ? "YES" : "NO") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
