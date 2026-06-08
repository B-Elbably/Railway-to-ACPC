#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 2e3;
int g[N];

// int mex(set<int> &s) {
//     int x = 0;
//     while (s.count(x)) ++x;
//     return x;
// }

void pre() {
    for (int i = 3; i < N; ++i) {
        set<int> s;
        int mex = 0;
        for (int j = 1; j < i; ++j) {
            if (j == i - j) continue;
            s.insert(g[j] ^ g[i - j]);
        }
        while (s.count(mex)) ++mex;
        g[i] = mex;
    }
}

void solve() {
    int n;
    cin >> n;
    if (n >= N) cout << "first" << endl;
    else 
    cout << (g[n] != 0 ? "first" : "second") << endl;
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
