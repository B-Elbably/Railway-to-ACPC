#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int odd = 0, ev = 0, fo = 0;
    for (auto &x : a) {
        cin >> x;
        if (x & 1) odd++;
        else {
            if (x % 4 == 0) fo++;
            else ev++;
        }
    }
    // cout << odd << " " << ev << " " << fo << endl;
    cout << max({odd, ev, fo}) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
