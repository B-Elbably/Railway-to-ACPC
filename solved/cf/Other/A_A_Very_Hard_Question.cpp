#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int a, b;
    cin >> a >> b;
    cout << (a * 100) / (100 + b) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
