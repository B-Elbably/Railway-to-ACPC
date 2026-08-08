#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &ai : a) cin >> ai;
    for (int i = 30; i >= 0; --i) {
        // int mask = (1 << i);
        vector<int> ones, zeros;
        for (int ai: a) {
            int o1 = (ai >> i) & 1;
            if (o1) ones.push_back(ai);
            else zeros.push_back(ai);
        }
        int o2 = (x >> i) & 1;
        if (o2) {
            if (ones.empty()) {
                cout << "-1\n";
                return;
            }
            a.swap(ones);
        }else {
            if (zeros.empty()) {
                cout << "-1\n";
                return;
            }
        }
    }
    int ans = a.size();
    if (!ans) ans = -1;
    int xx = (1 << 30) - 1;
    for (int ai: a) xx &= ai;
    if (xx != x) ans = -1;
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
