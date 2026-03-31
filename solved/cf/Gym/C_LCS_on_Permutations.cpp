#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, val;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> val;
        pos[val] = i;
    }

    vector<int> lis;
    for (int i = 0; i < n; i++) {
        cin >> val;
        int p = pos[val];
        auto it = lower_bound(lis.begin(), lis.end(), p);
        if (it == lis.end()) lis.push_back(p);
        else *it = p;
    }

    cout << lis.size() << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
