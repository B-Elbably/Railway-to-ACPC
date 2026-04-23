#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    // vector<int> a(n * 3);
    // iota(all(a), 1);
    int i = 1, j = n * 3;
    // for (int c: a) cout << c << " ";
    // cout << endl;
    for (int k = 0; k < n; ++k) {
        cout << i++ << " " << j-- << " " << j-- << " ";
    }cout << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
