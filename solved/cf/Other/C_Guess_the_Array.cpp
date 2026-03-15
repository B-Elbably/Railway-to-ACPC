#include <bits/stdc++.h>
using namespace std;

#define int long long

int ask(int i, int j) {
    cout << "? " << i << " " << j << '\n';
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;

    vector<int> pref(4), ans(n);

    // First 3 queries
    pref[1] = ask(1, 2);
    pref[2] = ask(2, 3);
    pref[3] = ask(3, 1);

    int sum = pref[1] + pref[3] - pref[2];

    ans[0] = sum / 2;
    ans[1] = pref[1] - ans[0];
    ans[2] = pref[2] - ans[1];

    for (int i = 4; i <= n; ++i) {
        ans[i - 1] = ask(1, i) - ans[0];   // FIXED INDEX
    }

    cout << "! ";
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << '\n';
    cout.flush();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}