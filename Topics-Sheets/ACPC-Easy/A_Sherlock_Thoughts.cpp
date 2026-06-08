#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld double long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    ld n, m;
    cin >> n >> m;
    cout << n * m * 2 << endl;
} 

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
