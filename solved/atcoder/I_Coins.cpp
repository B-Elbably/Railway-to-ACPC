#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
vector<double> a;
const int N = 3e3 + 1;
double memo[N][N];
int vis[N][N];

double go(int i, int head) {
    if (i == n) return head * 2 > n;
    double &ret = memo[i][head];
    if (vis[i][head]) return ret;
    vis[i][head] = 1;
    double op1 = (1 - a[i]) * go(i + 1, head);
    double op2 = a[i] * go(i + 1, head + 1);
    return ret = op1 + op2;
}

void solve() {
    cin >> n;
    memset(memo, -1.0, sizeof(memo));
    memset(vis, 0, sizeof(vis));
    a.resize(n);

    for (auto &x : a) cin >> x;
    cout << fixed << setprecision(10) << go(0, 0) << endl;  
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
