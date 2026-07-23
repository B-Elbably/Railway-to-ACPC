#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;

struct pt {
    int x, y;
    pt() : x(0), y(0) {}
    pt(int _x, int _y) : x(_x), y(_y) {}
    pt operator+(const pt &other) const {
        return {x + other.x, y + other.y};
    }
    pt operator-(const pt &other) const {
        return {x - other.x, y - other.y};
    }
};

int cross(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}

int fast_pow(int base, int exp) {
    int res = 1;
    base %= MOD;
    if (base < 0) base += MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int areaPolygon(const vector<pt>& polygon) {
    int total_area = 0;
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        pt curr = polygon[i];
        pt next = polygon[(i + 1) % n];
        total_area += cross(curr, next);
    }
    return abs(total_area);
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];
    vector<int> area(n + 1), active(n + 1);
    for (int i = 1; i <= n; i++) {
        int sz; cin >> sz;
        vector<pt> polygon(sz);
        for (auto &p : polygon) {
            cin >> p.x >> p.y;
        }
        area[i] = areaPolygon(polygon);
    }
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        active[i] = area[i] - area[i - 1];
        p[i] = active[i] * s[i];
        p[i] += p[i - 1];
    }

    int idx = 1;
    long double mx = -1.0;
    for (int i = 1; i <= n; i++) {
        long double cur = (long double)p[i] / area[i];
        if (cur > mx) {
            mx = cur;
            idx = i;
        }
    }
    vector<int> E(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] %= MOD;
        area[i] %= MOD;
        E[i] = (p[i] * fast_pow(area[i], MOD - 2)) % MOD;
    }
    int ans = (k * E[idx]) % MOD;
    ans = (ans + (m - k) * E[n]) % MOD;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}