#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < 20; ++i) {
        cout << i << ":";
        for (int j = i + 1; j < 32; ++j) {
            if ((i ^ j) < i) cout << " " << j;
        }
        cout << endl;
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
