#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int x = 0; x < n; ++x) cin >> a[x];
    set<int> s;
    int ans = 0, i = 0;

    for (int j = 0; j < n; ++j) {
        for(;;) {
            auto it = s.lower_bound(a[j] - k + 1);
            if (it != s.end() && *it <= a[j] + k - 1) {
                s.erase(a[i]);
                i++;
            } else {
                break;
            }
        }
        s.insert(a[j]);
        ans += (j - i);
    }
    cout << ans << "\n";
}

// void solve() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> a(n);
//     for (auto &x : a) cin >> x;
//     multiset<int> s;
//     multiset<int> diff;

//     auto add = [&](int x) {
//         auto it = s.insert(x);
//         auto prv = it, nxt = it;
//         bool has_prv = (it != s.begin());
//         nxt++;
//         bool has_nxt = (nxt != s.end());
//         if (has_prv) prv--;
//         if (has_prv && has_nxt) diff.erase(diff.find(*nxt - *prv));
//         if (has_prv) diff.insert(*it - *prv);
//         if (has_nxt) diff.insert(*nxt - *it);
//     };

//     auto remove = [&](int x) {
//         auto it = s.find(x);
//         auto prv = it, nxt = it;
//         bool has_prv = (it != s.begin());
//         nxt++;
//         bool has_nxt = (nxt != s.end());
//         if (has_prv) prv--;

//         if (has_prv) diff.erase(diff.find(*it - *prv));
//         if (has_nxt) diff.erase(diff.find(*nxt - *it));
//         if (has_prv && has_nxt) diff.insert(*nxt - *prv);
//         s.erase(it);
//     };

//     int ans = 0;
//     int i = 0, j = 0;
//     while (j < n) {
//         add(a[j]);
//         while (!diff.empty() && *diff.begin() < k) {
//             remove(a[i]);
//             i++;
//         }
//         ans += (j - i);
//         j++;
//     }
//     cout << ans << endl;
// }

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t; 
    while (t--) solve();
    return 0;
}