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
    multiset<int> ms;
    for (int i = 0; i < k; ++i){
        ms.insert(a[i]);
    }
    auto it = next(ms.begin(), (k - 1) / 2);
    cout << *it << ' ';
    for (int i = k; i < n; i++) {
        int add = a[i];
        int rem = a[i - k];
        ms.insert(add);
        if (add < *it) it--;
        if (rem <= *it) it++;
        ms.erase(ms.find(rem));
        cout << *it << " ";
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
