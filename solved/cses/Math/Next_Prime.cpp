#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

bool prime(int x) {
    if (x < 2) {
        return false;
    }
    if (x % 2 == 0) {
        return x == 2;
    }
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n; n++;
    if (n > 2 && n % 2 == 0) n++;
    while (!prime(n)) n += 2;
    cout << n << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
