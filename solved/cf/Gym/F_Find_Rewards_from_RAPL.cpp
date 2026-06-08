#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    unordered_map<int, int> mp;
    for (int x: a) mp[x]++;

    while (q--) {
        int idx, add;
        cin >> idx >> add;
        --idx;
        mp[a[idx]]--;
        if (mp[a[idx]] == 0) mp.erase(a[idx]);
        a[idx] += add;
        mp[a[idx]]++;
        cout << mp.size() << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
