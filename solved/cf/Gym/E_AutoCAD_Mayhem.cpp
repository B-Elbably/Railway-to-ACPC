#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int a, b, c;
    int d, e, f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    vector<int> x = {a, b, c};
    sort(all(x));
    do {
        if (x[0] * e != x[1] * d) continue;
        if (x[0] * f != x[2] * d) continue;
        if (x[1] * f != x[2] * e) continue;
        cout << "YES" << endl;
        return;
    } while (next_permutation(all(x)));
    cout << "NO" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
