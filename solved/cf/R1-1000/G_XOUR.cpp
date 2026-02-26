#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, set<int>> indices;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        indices[a[i]].insert(i);
    }
    for (int i = 0; i < n; ++i) {
        indices[a[i]].erase(i);
        int best = a[i];
        int ix = -1;

        for (int j = 0; j < 4; ++j) {
            int now = a[i] ^ j;
            if (now < best && !indices[now].empty()) {
                best = now;
                ix = *indices[now].begin();
            }
        }

        if (ix != -1) {
            indices[best].erase(ix);
            indices[a[i]].insert(ix);
            swap(a[i], a[ix]);
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}