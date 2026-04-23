#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(all(a));
    int ans = 0;
    // for (int i = 0; i < n; i++) cout << a[i] << " ";
    // cout << endl;
    // vector<int> used(n + 1);
    // int j = n - 1;
    // for (int i = n - 2; i >= 0 && j >= 1; i--) {
    //     if (used[i]) continue;
    //     while (used[j]) j--;
    //     i = min(i, j - 1);
    //     // while (i >= 0 && used[i]) i--;
    //     while (i >= 0 && ((a[j] - a[i] < k) || used[i])) i--;
    //     if ((i >= 0) && (a[j] - a[i] >= k)) {
    //         used[i]++;
    //         used[j]++;
    //         ans++;
    //     }    
    // }
    int j = n / 2;
    // for (int i = 0; i <)
    for (int i = 0; ((i < n / 2) && (j < n)); ++i) {
        if (a[j] - a[i] >= k) {
            ans++;
        }else i--;
        j++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
