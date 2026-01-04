#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "NO" << endl;
        return;
    }
    n <<= 1;
    vector<int> res(n);
    res[0] = 1;
    for (int i = 1; i < n; i++) {
        res[i] = res[i - 1] + 1 + (i % 2 ? 2 : 0);
        res[i] %= n;
        if (res[i] == 0) res[i] = n;
    };
    cout << "YES" << endl;
    for (int &x : res) {
        cout << x << " ";
    }

    // vector<int> a(2 * n);
    // iota(all(a), 1);

    // do {
    //     vector<int> sums(2 * n);

    //     for (int i = 0; i < 2 * n; i++) {
    //         int sm = 0;
    //         for (int j = 0; j < n; j++) {
    //             sm += a[(i + j) % (2 * n)];
    //         }
    //         sums[i] = sm;
    //     }

    //     sort(all(sums));
    //     bool ok = (sums.back() - sums.front()) <= 1;

    //     if (ok) {
    //         for (int x : a) cout << x << " ";
    //         cout << endl;
    //     }

    // } while (next_permutation(all(a)));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
