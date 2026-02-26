#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, s , x;
    cin >> n >> s >> x;
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        int ai; cin >> ai;
        sm += ai;
    }
    if (sm == s || (sm < s && (s - sm) % x == 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}


