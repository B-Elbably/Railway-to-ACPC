#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e5 + 5;
int n, p, k;
struct person
{
    int ai;
    vector<int> s;
};

vector<person> a;
int memo[N][1 << 8];
int go(int i, int mask) {
    if (i == n) return mask == ((1 << p) - 1) ? 0 : -1e18;
    int &ret = memo[i][mask];
    if (~ret) return ret;
    int cnt = __builtin_popcount(mask);
    ret = go(i + 1, mask);
    if (i - cnt < k) {
        ret += a[i].ai;
    }
    for (int j = 0; j < p; j++) {
        if ((mask & (1 << j))) continue;
        ret = max(ret, go(i + 1, mask | (1 << j)) + a[i].s[j]);
    }
    return ret;
}

void solve() {
    memset(memo, -1, sizeof(memo));
    cin >> n >> p >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].ai;
    }
    for (int i = 0; i < n; i++) {
        a[i].s.resize(p);
        for (int j = 0; j < p; j++) {
            cin >> a[i].s[j];
        }
    }
    sort(all(a), [](const person &a, const person &b) {
        return a.ai > b.ai;
    });
    cout << go(0, 0) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
