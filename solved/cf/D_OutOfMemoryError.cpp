#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n , m , h;
    cin >> n >> m >> h;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<pair<int, int>> op;
    for (int i = 0; i < m; ++i) {
        int bi, ci;
        cin >> bi >> ci; bi--;
        op.push_back({bi, ci});
        a[bi] += ci;
        if (a[bi] > h) {
            while (!op.empty())
            {
                auto [idx, val] = op.back();
                op.pop_back();
                a[idx] -= val;
            }
        }
    }
    for (auto x : a) cout << x << ' ';
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
