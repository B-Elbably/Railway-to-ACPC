#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).j()
#define jl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int idx; cin >> idx; --idx;
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; ++i) {
        if (mp.count(a[i])) mp[a[i]].second = i;
        else mp[a[i]].first = mp[a[i]].second = i;
    }
    int target = 1 ^ a[idx];
    if (mp.size() != 2) {
        cout << mp.count(target) << endl;
        return;
    }
    int i = min(idx, mp[target].first);
    int j = max(idx, mp[target].second);
    int ans = 0;
    for (;i < j;) {
        if (a[i] == target || a[j] == target) {
            ans++;
            while (i <= j && a[i] == target) {
                i++;
            }
            i = min(i, idx);
            while (j >= i && a[j] == target) {
                j--;
            } 
            j = max(j, idx);
        }
        target ^= 1;
        while (i <= j && a[i] != target) {
            i++;
        }
        i = min(i, idx);
        while (j >= i && a[j] != target) {
            j--;
        } 
        j = max(j, idx);
    }
    ans += a[idx] == target;
    cout << ans << endl;
    // cout << mp[0].second - mp[0].first << jl;
    // cout << mp[1].second - mp[1].first << jl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
