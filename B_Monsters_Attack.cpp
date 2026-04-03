#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'


struct Monster {
    int idx, val;
    bool operator < (const Monster &other) const {
        return idx < other.idx;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<Monster> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].val;
    for (int i = 0; i < n; i++) {
        cin >> a[i].idx;
        a[i].idx = abs(a[i].idx);
    }
    sort(all(a));
    vector<Monster> b;
    b.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i].idx == b.back().idx) {
            b.back().val += a[i].val;
        } else {
            b.push_back(a[i]);
        }
    }
    int sum = 0;
    int idx = 0;
    for (auto &m : b) {
        sum += (m.idx - idx) * k;
        if (sum < m.val) {
            cout << "NO" << endl;
            return;
        }
        sum -= m.val;
        idx = m.idx;
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
