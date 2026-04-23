#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int a, b;
    cin >> a >> b;
    if ((!a && b % 2 == a) || a > b) {
        cout << "NO" << endl; return;
    }
    if ((a + b) % 2 == 0) a--, b++;
    cout << "YES" << endl;
    for (int i = 1; i <= 2 * a; i++) {
        cout << i << " " << i + 1 << "\n";
    }   
    for (int i = 2 * a + 2; i <= (a + b); i++) {
        cout << 1 << " " << i << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
