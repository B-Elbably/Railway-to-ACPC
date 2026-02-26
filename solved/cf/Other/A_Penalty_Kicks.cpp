#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n, x , y;

void solve() {
    cin >> n >> x >> y;
    if (x > n || y > n) {
        cout << "Impossible\n";
        return;
    }
    if (x < y) swap(x, y);
    if (x > n - x + y + 1)
        cout << "Impossible\n";
    else
        cout << "Possible\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
// 
