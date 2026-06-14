#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < k; ++i) {
        string t;
        int sum = 0;
        for (int j = i; j < n; j += k) {
            sum += s[j] - '0';
        }
        if (sum & 1) {
            cout << "NO\n";
            return; 
        }
    }
    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
