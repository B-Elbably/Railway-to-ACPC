#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    int A = abs(x - z);
    int B = abs(y - z);
    if (A < B) {
        cout << "Cat A" << endl;
    } else if (B < A) {
        cout << "Cat B" << endl;
    } else {
        cout << "Mouse C" << endl;
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
