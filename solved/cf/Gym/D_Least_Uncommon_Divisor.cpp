#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

bool check(int a) {
    int bb = 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            if (bb == 1) return false;
            bb = 1;
            while (a % i == 0) a /= i;
        }
    }
    if (a > 1) {
        if (bb == 1) return false;
    }
    return true;
}

vector<int> factorize(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (check(i)) factors.push_back(i);
            if (i != n / i) {
                if (check(n / i)) factors.push_back(n / i);
            }
        }
    }
    if (n > 1) factors.push_back(n);
    sort(all(factors));
    return factors;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> factors = factorize(x);
    for (auto &ai : a) {
        cin >> ai;
        int ok = 1;
        for (int f : factors) {
            if (ai % f != 0) {
                cout << f << endl;
                ok = 0;
                break;
            }
        }
        if (ok) cout << -1 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}