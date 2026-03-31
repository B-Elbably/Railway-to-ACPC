#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 200005;
int bit[N], n;

void update(int idx, int val) {
    for (; idx <= n; idx += idx & -idx)
        bit[idx] = max(bit[idx], val);
}

int query(int idx) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx)
        res = max(res, bit[idx]);
    return res;
}

void solve() {
    cin >> n;
    vector<int> h(n), a(n);
    for (int &x : h) cin >> x;
    for (int &x : a) cin >> x;

    for (int i = 0; i < n; i++) {
        int mx = query(h[i] - 1);
        update(h[i], mx + a[i]);
    }

    cout << query(n) << endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}