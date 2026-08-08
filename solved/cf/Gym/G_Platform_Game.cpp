#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct plat {
    int l, r, y;
    bool operator<(const plat &other) const {
        if (y != other.y) return y > other.y;
        return l < other.l;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<plat> a(n);
    for (auto &x : a) cin >> x.l >> x.r >> x.y;
    sort(all(a));
    int x, y; 
    cin >> x >> y;
    for (int i = 0; i < n; ++i) {
        if (a[i].y <= y) y = a[i].y;
        else continue;
        if (a[i].l < x && x < a[i].r) {
            x = a[i].r;
        }
    }
    cout << x << endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
