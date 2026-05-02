#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
vector<int> a;

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x;
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
    sort(all(a));
    // int ans = 0;
    // for (int x: a) {
    //     if (x == ans) ans++;
    //     else {
    //         if ((x - 1) / 2 >= ans) ans++;
    //     }
    // }
    int l = 0, r = n;
    vector<int> freq(n + 1);
    for (; l <= r; ) {
        int mid = (l + r) / 2;
        int ok = 1;
        for (int i = 0; i < mid; ++i) freq[i] = 0;
        vector<int> rem;
        for (int x: a) {
            if (x < mid && !freq[x]) {
                freq[x]++;
            } else {
                rem.push_back((max(x - 1, 0LL)) / 2);
            }
        }
        sort(all(rem));
        int j = 0;
        for (int i = 0; i < mid && ok; ++i) {
            if (!freq[i]) {
                while (j < rem.size() && rem[j] < i) j++;
                if (j == rem.size()) ok = 0;
                j++;
            }
        }
        if (ok) l = mid + 1;
        else r = mid - 1;
    }
    cout << l - 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
