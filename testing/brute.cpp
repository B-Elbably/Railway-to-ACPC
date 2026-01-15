#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll flo(ll x) { return x / 2; }
ll cei(ll x) { return (x + 1) / 2; }

void solve() {
    ll x, n, m;
    cin >> x >> n >> m;

    set<tuple<ll,ll,ll>> vis;
    queue<tuple<ll,ll,ll>> q;

    q.push({x, 0, 0});
    vis.insert({x, 0, 0});

    ll mn = LLONG_MAX, mx = LLONG_MIN;

    while (!q.empty()) {
        auto [cx, fn, cm] = q.front(); q.pop();

        if (fn == n && cm == m) {
            mn = min(mn, cx);
            mx = max(mx, cx);
            continue;
        }

        if (fn < n) {
            ll nx = flo(cx);
            if (!vis.count({nx, fn + 1, cm})) {
                vis.insert({nx, fn + 1, cm});
                q.push({nx, fn + 1, cm});
            }
        }

        if (cm < m) {
            ll nx = cei(cx);
            if (!vis.count({nx, fn, cm + 1})) {
                vis.insert({nx, fn, cm + 1});
                q.push({nx, fn, cm + 1});
            }
        }
    }

    cout << mn << " " << mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
