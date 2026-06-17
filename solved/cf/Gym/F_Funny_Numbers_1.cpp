#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e6 + 5;
const int M = 1e3 + 5;
int ans[N];

int f(int n) {
    int res = 0;
    while (n) {
        int d = n % 10;
        res += d * d;
        n /= 10;
    }
    return res;
}

int mx;

set<int> seen;
void build() {
    for (int i = 1; i < N; ++i) {
        if (i > M) {
            ans[i] = ans[f(i)];
            continue;
        }
        int cnt = 0;
        int x = i;
        while (x > 10) {
            seen.insert(x);
            x = f(x);
            cnt ++;
        }
        mx = max(mx, cnt);
        seen.clear();
    }
}

void solve() {
    memset(ans, -1, sizeof ans);
    int a, b;
    cin >> a >> b;
    build();
    int sum = 0;
    for (int i = a; i <= b; ++i) {
        int mn = i;
        int x = i;
        for (int j = 0; j < 20; ++j) {
            x = f(x);
            mn = min(mn, x);
        }
        sum += mn;
    }
    // cout << mx << endl;
    cout << sum << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}