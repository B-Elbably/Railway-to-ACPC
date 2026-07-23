#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
struct interval {
    int l, r, cost;
    bool operator<(const interval &other) const {
        if (l != other.l) return l < other.l;
        if (r != other.r) return r < other.r;
        return cost > other.cost;
    }
};
vector<interval> a;
const int N = 2e5 + 5;
int memo[N];

int dp(int idx) {
    if (idx == a.size()) return 0;
    int &ret = memo[idx];
    if (~ret) return ret;
    ret = dp(idx + 1);
    interval target = {a[idx].r + 1, 0, 0};
    int nxt = lower_bound(all(a), target) - a.begin();
    ret = max(ret, a[idx].cost + dp(nxt));
    return ret;
}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x.l >> x.r >> x.cost;
    sort(all(a));
    memset(memo, -1, sizeof(memo));
    cout << dp(0) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
