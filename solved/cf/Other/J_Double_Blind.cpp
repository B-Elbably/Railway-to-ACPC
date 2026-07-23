#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

bool ask(int m, int v) {
    cout << "? " << m << " " << v << "\n";
    cout.flush();
    bool res; cin >> res;
    return res;  
}

void solve() {
    int a = 0, b = 0;
    int xr = 0;
    int mx = 59;
    int idx = -1;
    for (int i = 59; i >= 0; --i) {
        int num = 1LL << i;
        if (ask(num, num)) {
            xr |= num;
            if (~idx) continue;
            idx = i;
        }
    }
    b = 1LL << idx;
    for (int i = 59; i >= 0; --i) {
        if (idx == i) continue;
        int num = b + (1LL << i);
        if (ask(num, num)) b = num;
    }
    a = xr ^ b;
    cout << "! " << a << " " << b << "\n";
    cout.flush();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
