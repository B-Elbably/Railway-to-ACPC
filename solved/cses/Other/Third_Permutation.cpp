#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);

    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    // Shift a by 1
    for (int i = 0; i < n; ++i)
        c[i] = a[(i + 1) % n];

    vector<int> bad;

    for (int i = 0; i < n; ++i) {
        if (c[i] == b[i])
            bad.push_back(i);
    }

    // Fix bad positions
    for (int i : bad) {
        if (c[i] != b[i])
            continue;

        bool done = false;

        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;

            if (c[j] == b[i] || c[i] == b[j])
                continue;

            if (c[j] == a[i] || c[i] == a[j])
                continue;

            swap(c[i], c[j]);
            done = true;
            break;
        }

        if (!done) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    // Verify
    for (int i = 0; i < n; ++i) {
        if (c[i] == a[i] || c[i] == b[i]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    for (int x : c)
        cout << x << ' ';

    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}