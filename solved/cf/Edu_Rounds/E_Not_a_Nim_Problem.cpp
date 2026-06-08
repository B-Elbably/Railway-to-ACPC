#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 10000005;
int g[N];

void pre() {
    g[1] = 1;
    int idx = 1;
    for (int i = 3; i < N; i += 2) {
        if (g[i]) continue;
        g[i] = ++idx;
        for (int j = i * i; j < N; j += i * 2) {
            if (g[j]) continue;
            g[j] = idx;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int p = 0;
    for (int i = 0; i < n; ++i) {
        p ^= g[a[i]];
    }
    cout << (p != 0 ? "Alice" : "Bob") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pre();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
