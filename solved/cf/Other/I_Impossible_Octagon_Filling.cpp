#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    int k = sqrt((n - 1) / 4);
    while (k * (k + 1) <= (n - 1) / 4) k++;
    int n_prime = n - 4LL * k * (k - 1);
    int r = (n_prime - 1) % (2 * k) + 1;
    
    cout << 4LL * k * k + 4LL * (k - r) * (k - r) << "\n";

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
