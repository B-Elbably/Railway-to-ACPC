#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e5 + 5; 
vector<int> divs[N];
vector<int> muls[N];
void pre() {
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            divs[j].push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    set<int> s(all(a));
    // int m = 15;
    // for (int i = 1; i < m; ++i) {
    //     for (int j = i + 1; j < m; ++j) {
    //         if (!(i ^ j)) continue;
    //         cout << i << ", " << j << ": ";
    //         cout << (__gcd(i, j) * 10000) / (i ^ j) << endl;
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    vector<int> d;
    for (int i : s) {
        for (int j : divs[i]) {
            if (muls[j].empty()) d.push_back(j);
            muls[j].push_back(i);
        }
    }
    for (int i : d) {
        int m = muls[i].size();
        for (int j = 1; j < m; ++j) {
            int x = muls[i][j];
            int y = muls[i][j - 1];
            ans = max(ans, (__gcd(x, y) * 10000) / (x ^ y));
        }
        muls[i].clear();
    }
    cout << ans << endl;
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
