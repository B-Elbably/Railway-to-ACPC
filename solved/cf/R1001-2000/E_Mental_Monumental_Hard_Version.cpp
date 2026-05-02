#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
vector<int> b;

void solve() {
    int n;
    cin >> n;
    b.resize(n);
    for (auto &v : b) cin >> v;
    // for (int i = 1; i < n; ++i) {
    //     cout << i << ": ";
    //     int mx = 0;
    //     for (int j = 1; j < i; ++j) {
    //         mx = max(mx, i % j);
    //         // cout << i % j << " ";
    //     }
    //     cout << mx;
    //     cout << " " << (i - 1) / 2 << endl;
    //     // cout << i << endl;
    // }
    // sort(all(a));
    // int ans = 0;
    // for (int x: a) {
    //     if (x == ans) ans++;
    //     else {
    //         if ((x - 1) / 2 >= ans) ans++;
    //     }
    // }
    multiset<int> a;
    int idx = 0;
    int last = 0;
    int mx = 0;
    for (int val : b) {
        a.insert(val);
        int l = last, r = ++mx;
        while (l <= r) {
            int mid = (l + r) / 2;
            bool ok = 1;
            vector<int> freq(mid, 0);
            multiset<int> rem;
            for (auto &x : a) {
                if (x < mid) {
                    freq[x]++;
                } else {
                    rem.insert(max(x - 1, 0LL) / 2);
                }
            }
            int j = 0;
            for (int i = 0; i < mid && ok; i++) {
                if (!freq[i]) {
                    while (j < rem.size() && *next(rem.begin(), j) < i) j++;
                    if (j == rem.size()) ok = 0;
                    j++;
                }
            }
            if (ok) l = mid + 1;
            else r = mid - 1;
        }

        cout << l - 1 << " ";
        last = l - 1;
    }

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