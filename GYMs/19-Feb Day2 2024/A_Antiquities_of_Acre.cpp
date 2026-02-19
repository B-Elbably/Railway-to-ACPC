#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n , x , h , m , s;
    cin >> n >> x >> h >> m >> s;
    s += h * 3600 + m * 60;
    n -= (s * x);
    cout << max(0LL, n) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}