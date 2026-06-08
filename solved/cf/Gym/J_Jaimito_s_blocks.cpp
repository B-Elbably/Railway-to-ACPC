#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<vector<int>> a(n), b(n);
    vector<int> in, out;
    
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (auto &x : a[i]) {
            cin >> x;
            in.push_back(x);
        }
    }

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        b[i].resize(k);
        for (auto &x : b[i]) {
            cin >> x;
            out.push_back(x);
        }
    }
    sort(all(in));
    sort(all(out));
    if (in != out) {
        cout << "N" << endl;
        return;
    }
    if (n == 1 || n >= 3) {
        cout << "S" << endl;
        return;
    }
    if (n == 2) {
        if (in.empty()) {
            cout << "S" << endl;
            return;
        }
        int m = in.front();
        auto strip = [&](const vector<int>& tower) {
            vector<int> res;
            for (int x : tower) {
                if (x != m) res.push_back(x);
            }
            return res;
        };
        if (strip(a[0]) == strip(b[0]) &&
            strip(a[1]) == strip(b[1])) {
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}