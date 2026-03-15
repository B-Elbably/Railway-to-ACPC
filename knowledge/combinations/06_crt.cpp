#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int extgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

// Returns {ok, value}. If no solution -> {false, 0}
pair<bool, int> crt(const vector<int>& a, const vector<int>& m) {
    int n = a.size();
    if (n == 0 || (int)m.size() != n) return {false, 0};

    int ans = a[0];
    int l = m[0];

    for (int i = 1; i < n; i++) {
        int x, y;
        int g = extgcd(l, m[i], x, y);
        int diff = a[i] - ans;

        if (diff % g != 0) return {false, 0};

        int step = m[i] / g;
        int mult = ((diff / g) % step) * (x % step) % step;
        if (mult < 0) mult += step;

        if (l != 0 && step > LLONG_MAX / l) return {false, 0};
        int mod = l * step;

        if (mult != 0 && l > LLONG_MAX / mult) return {false, 0};
        int add = l * mult;

        if (ans > LLONG_MAX - add) return {false, 0};
        ans = (ans + add) % mod;
        if (ans < 0) ans += mod;

        l = mod;
    }

    return {true, ans};
}

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
