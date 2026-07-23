#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e6 + 5;
int freq[N], f[N], g[N];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x, freq[x]++;
    for (int i = 1; i < N; ++i) {
        int cnt = 0;
        for (int j = i; j < N; j += i) {
            cnt += freq[j];
        }
        f[i] = cnt * (cnt - 1) / 2;
    }
    for (int i = N - 1; i >= 1; --i) {
        g[i] = f[i];
        for (int j = 2 * i; j < N; j += i) {
            g[i] -= g[j];
        }
    }
    cout << g[1] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
