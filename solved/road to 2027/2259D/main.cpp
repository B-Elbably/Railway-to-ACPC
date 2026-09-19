#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    vector<int> ans(n, -1);
    int ok = 1;
    for (int i = 0; i < n; ++i){
        if (mp[i].size() >= 2) {
            for (int j: mp[i]) {
                ans[j] = 1;
            }
            ans[mp[i].back()] = 2;
        }
        else if (mp[i].size() == 1) {
            if (i == 0) {
                ok = 0;
            }
            break;
        }
    }
    if (!ok) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i: ans) {
        if (i == -1) cout << "C";
        else if (i == 1) cout << "A";
        else cout << "B";
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
