#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

// Brute force: returns all valid permutations
vector<vector<int>> brute(int n) {
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    vector<vector<int>> valid;

    do {
        bool ok = true;

        for (int i = 2; i <= n - 1; i++) {
            int need = a[i - 1];
            if (need < 1 || need > n) {
                ok = false;
                break;
            }

            bool found = false;
            for (int j = i - 1; j < n; j++) {
                if ((a[j] ^ i) == need) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                ok = false;
                break;
            }
        }

        if (ok) valid.push_back(a);

    } while (next_permutation(a.begin(), a.end()));

    return valid;
}

void solve() {
    int n; cin >> n;
    vector<int> res(n);
    
    res[0] = n - (n & 1)    ;
    for (int i = 1; i <= n - 2; i += 2) {
        res[i] = 2 + i;
        res[i + 1] = i + 1;
    }
    res[n - 1] = 1;
    for (auto x : res) cout << x << ' ';
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    // auto valid = brute(n);
    // auto myres = solve(n);

    // bool found = false;
    // for (auto &v : valid) {
    //     if (v == myres) {
    //         found = true;
    //         break;
    //     }
    // }

    // cout << "My solve() result: ";
    // for (auto x : myres) cout << x << ' ';
    // cout << endl;
    return 0;
}
