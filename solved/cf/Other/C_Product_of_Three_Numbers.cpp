#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 2; i * i <= n && a.size() < 2; i++) {
        if (n % i == 0) {
            a.push_back(i); n /= i;
        }
    }
    if (a.size() < 2 || n == 1 || n == a[0] || n == a[1]) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    cout << a[0] << " " << a[1] << " " << n << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
