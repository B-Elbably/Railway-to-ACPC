#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
struct tree
{
    int x, h;
};
const int N = 1e5 + 5;
vector<tree> a;
int n;
int memo[N][3];
int go(int i, int status) {
    if (i >= n - 1) return 0;
    int &ret = memo[i][status];
    if (~ret) return ret;
    ret = go(i + 1, 0);
    int last = a[i - 1].x;
    if (status == 2) last += a[i - 1].h;
    if (last < a[i].x - a[i].h) {
        ret = max(ret, go(i + 1, 1) + 1);
    }
    if (a[i].x + a[i].h < a[i + 1].x) {
        ret = max(ret, go(i + 1, 2) + 1);
    }
    return ret;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x.x >> x.h;
    memset(memo, -1, sizeof(memo));
    if (n < 3) {
        cout << n << endl;
        return;
    }
    cout << go(1, 0) + 2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
