#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct Range {
    int l, r, id;
};

void solve() {
    int n;
    cin >> n;
    vector<Range> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }

    sort(all(a), [](const Range &x, const Range &y) {
        if (x.l == y.l) return x.r > y.r;
        return x.l < y.l;
    });

    vector<int> contains(n, 0), contained(n, 0);

    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].r <= mx) {
            contained[a[i].id] = 1;
        }
        mx = max(mx, a[i].r);
    }

    int mn = 2e18;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i].r >= mn) {
            contains[a[i].id] = 1;
        }
        mn = min(mn, a[i].r);
    }

    for (int x: contains) cout << x << " ";
    cout << endl;
    for (int x: contained) cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}