#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            ans++;
        }
    }
    int add = 0;
    for (int i = 0; i < n - 2; ++i) {
        vector<int> temp;
        for (int j = i; j < i + 3; ++j) {
            temp.push_back(a[j]);
        }
        if (temp[0] == temp[1] && temp[1] != temp[2]) {
            if (i + 3 == n || a[i + 3] != temp[0]) {
                add = max(add, 1LL);
            }
        }
        if (temp[0] != temp[1] && temp[1] == temp[2]) {
            if (i == 0 || a[i - 1] != temp[2]) {
                add = max(add, 1LL);
            }
        }
    }

    for (int i = 0; i < n - 3; ++i) {
        vector<int> temp;
        for (int j = i; j < i + 4; ++j) {
            temp.push_back(a[j]);
        }

        if (temp[0] == temp[1] &&
            temp[2] == temp[3] &&
            temp[1] != temp[2]) {
            add = max(add, 2LL);
        }
    }

    cout << ans + add << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
