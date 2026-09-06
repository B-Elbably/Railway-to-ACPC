#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int fact[21];

void solve() {
    int type, n;
    cin >> type >> n;
    int k;
    vector<int> a(n);
    iota(all(a), 1);

    // type 1: Given k, find the k-th permutation of [1..n]
    if (type == 1) {
        cin >> k; k--;
        for (int i = n - 1; i >= 0; i--) {
            int idx = k / fact[i];
            cout << a[idx] << " ";
            a.erase(a.begin() + idx);
            k %= fact[i];
        }
        cout << '\n';
    }
    // type 2: Given a permutation of [1..n], find its order k
    else {
        k = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            int idx = find(all(a), x) - a.begin();
            k += idx * fact[n - 1 - i];
            a.erase(a.begin() + idx);
        }
        cout << k + 1 << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1;
    for (int i = 1; i <= 20; ++i) fact[i] = fact[i - 1] * i;
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
