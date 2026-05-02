#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
vector<int> a;

int calc() {
    // cin >> n;
    // a.resize(n);

    // for (auto &x : a) cin >> x;

    int i = 0, j = 0;
    int ok2 = 0, ok3 = 0;
    int ans = 0;

    while (i < n) {
        while (j < n && !(ok2 > 0 && ok3 > 0)) {
            ok2 += (a[j] % 2 == 0);
            ok3 += (a[j] % 3 == 0);
            j++;
        }

        if (ok2 > 0 && ok3 > 0) {
            ans += (n - j + 1);
        } else {
            break;
        }

        ok2 -= (a[i] % 2 == 0);
        ok3 -= (a[i] % 3 == 0);
        i++;
    }

    return ans;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x;
    sort(all(a));
    // int mn = calc();
    // do {
        // if (calc() != 6) continue; 
        // for (auto x : a) cout << x << ' ';
        // cout << ": " << calc();
        // cout << endl;
        // mn = min(mn, calc());
    // }while (next_permutation(all(a)));
    // cout << calc() << endl;
    
    vector<int> res, a2, a3, a6, a0;
    for (auto x : a) {
        if (x % 6 == 0) {
            a6.push_back(x);
        } else if (x % 2 == 0) {
            a2.push_back(x);
        } else if (x % 3 == 0) {
            a3.push_back(x);
        } else {
            a0.push_back(x);
        }
    }
    for (auto x : a3) res.push_back(x);
    for (auto x : a0) res.push_back(x);
    for (auto x : a2) res.push_back(x);
    for (auto x : a6) res.push_back(x);
    for (auto x : res) cout << x << ' ';
    // a = res;
    // cout << mn << " " << calc();
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
