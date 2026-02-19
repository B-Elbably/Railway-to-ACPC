#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    
    if (b > a) {
        if (b & 1)
            cout << -1 << endl;
        else {
            int ans = 0;
            while (a < b) {
                a <<= 1;
                ans++;
            }
            if (a == b) {
                cout << (ans + 2) / 3 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    } else {
        int ans = 0;
        while (a % 2 == 0 && a > b) {
            a /= 2;
            ans++;
        }
        if (a == b) {   
            cout << (ans + 2) / 3 << endl;
        } else {
            cout << -1 << endl;
        }
    }    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
