#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (b == 1) {
        cout << "1/1";
    }else if (b == 2) {
        cout << "5/6";
    }else if (b == 3) {
        cout << "2/3";
    }else if (b == 4) {
        cout << "1/2";
    }else if (b == 5) {
        cout << "1/3";
    }else if (b == 6) {
        cout << "1/6";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
