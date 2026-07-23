#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e5 + 5;
int n, q;
int nxt[N], a[N], step[N];
const int S = 320;

void query(int x) {
    int ans = 1;
    while (nxt[x] < n) ans += step[x], x = nxt[x];
    while (a[x] + x < n) ans++, x += a[x];
    cout << x + 1 << " " << ans << endl;
}

void update(int x, int v) {
    int bi = x / S;
    a[x] = v;
    for (int i = x; i >= bi * S; i--) {
        int ni = i + a[i], mx = min(n, S * (bi + 1));
        if (ni >= mx) nxt[i] = ni, step[i] = 1;
        else nxt[i] = nxt[ni], step[i] = 1 + step[ni];
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = n - 1; i >= 0; i--) {
        int ni = i + a[i];
        int mx = min(n, S * (i / S + 1));
        if (ni >= mx) nxt[i] = ni, step[i] = 1;
        else nxt[i] = nxt[ni], step[i] = 1 + step[ni];
    }
    while (q--) {
        int type; cin >> type;
        int idx, v; cin >> idx; idx--;
        if (type == 1) {
            query(idx);
        }else {
            cin >> a[idx];
            update(idx, a[idx]);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
